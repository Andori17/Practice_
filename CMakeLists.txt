# CLion 友好的最低 CMake 版本
cmake_minimum_required(VERSION 3.16)

# 项目配置（英文名称，适配全英文文件）
project(
        CodePractice
        VERSION 1.0
        LANGUAGES C CXX
)

# ========================= 基础标准配置 =========================
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

# ========================= 输出目录配置（简洁清晰）=========================
set(OUTPUT_ROOT ${CMAKE_SOURCE_DIR}/build_output)
# 按「构建类型+平台」分目录，避免冲突
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_ROOT}/lib/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_ROOT}/lib/$<CONFIG>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_ROOT}/bin/$<CONFIG>)

# 适配 CLion 多配置切换（Debug/Release）
foreach(OUTPUT_CONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUT_CONFIG} OUTPUT_CONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUT_CONFIG_UPPER} ${OUTPUT_ROOT}/bin/${OUTPUT_CONFIG})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUT_CONFIG_UPPER} ${OUTPUT_ROOT}/lib/${OUTPUT_CONFIG})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUT_CONFIG_UPPER} ${OUTPUT_ROOT}/lib/${OUTPUT_CONFIG})
endforeach()

# ========================= 源文件收集（英文文件名专属）=========================
file(GLOB_RECURSE SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/*.c"
        "${CMAKE_SOURCE_DIR}/*.cpp"
        LIST_DIRECTORIES false  # 只收集文件，不收集目录
)

# 过滤排除无关文件/目录（CLion 辅助目录+构建目录）
list(FILTER SOURCE_FILES EXCLUDE REGEX
        "(/CMakeFiles/|/cmake-build-|/build_output/|/\\.idea/|/\\.git/|/test/|/docs/)"
)
list(FILTER SOURCE_FILES EXCLUDE REGEX "\\.(h|hpp|inc|txt|md|json)$")  # 只保留源文件

# ========================= 生成可执行目标（彻底解决 main 冲突）=========================
if(SOURCE_FILES)
    message(STATUS "找到 ${CMAKE_CURRENT_LIST_LENGTH} 个源文件，生成独立可执行目标：")
    foreach(SOURCE_FILE ${SOURCE_FILES})
        # 1. 提取文件名（不含路径和后缀）作为目标名（英文文件名直接可用，无冲突）
        get_filename_component(FILE_NAME_WE ${SOURCE_FILE} NAME_WE)

        # 2. 生成唯一目标名（避免不同目录下同名文件冲突，英文路径直接替换 / 为 _）
        file(RELATIVE_PATH RELATIVE_PATH ${CMAKE_SOURCE_DIR} ${SOURCE_FILE})
        string(REPLACE "/" "_" TARGET_NAME ${RELATIVE_PATH})  # 如 src_math_add

        # 3. 关键：每个目标只绑定一个源文件（彻底避免多个 main 冲突）
        add_executable(${TARGET_NAME} ${SOURCE_FILE})

        # 4. 配置目标属性（CLion 调试友好）
        set_target_properties(${TARGET_NAME} PROPERTIES
                OUTPUT_NAME ${FILE_NAME_WE}  # 输出文件名=原文件名（如 11.exe, runoob_p.exe）
                VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}  # 调试工作目录设为项目根
        )

        # 日志输出（清晰查看目标与文件的对应关系）
        message(STATUS "  - 目标：${TARGET_NAME}")
        message(STATUS "    源文件：${SOURCE_FILE}")
        message(STATUS "    输出路径：${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${FILE_NAME_WE}.exe")
    endforeach()
else()
    message(WARNING "未找到任何 .c/.cpp 源文件！请检查项目结构")
endif()

# ========================= 编译选项（CLion 调试/警告优化）=========================
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")  # MinGW/GCC/Clang
    add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter)
    # Debug 模式：保留完整调试信息，禁用优化（CLion 断点稳定）
    set(CMAKE_C_FLAGS_DEBUG "-g -O0 -ggdb")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -ggdb")
    # Release 模式：优化编译，减小体积
    set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
elseif(MSVC)  # 若使用 MSVC 编译器
    add_compile_options(/W4 /wd4100)
    set(CMAKE_C_FLAGS_DEBUG "/Zi /Od /MDd")
    set(CMAKE_C_FLAGS_RELEASE "/O2 /DNDEBUG /MD")
endif()

# ========================= CLion 体验优化 =========================
# 排除输出目录和辅助目录，避免 CLion 索引冗余文件
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY CLION_EXCLUDE_DIRS
        ${OUTPUT_ROOT}  # 构建输出目录
        .idea           # CLion 配置目录
        cmake-build-*   # CLion 默认构建目录
)

# 自动生成 .gitignore，避免提交构建产物
if(EXISTS ${OUTPUT_ROOT} AND NOT EXISTS ${OUTPUT_ROOT}/.gitignore)
    file(WRITE ${OUTPUT_ROOT}/.gitignore "*")
endif()