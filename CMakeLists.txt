cmake_minimum_required(VERSION 3.16)

# 项目配置
project(
        CodePractice
        VERSION 1.0
        LANGUAGES C CXX
)

# ========================= 基础标准配置 =========================
# C 标准配置
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# C++ 标准配置
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ========================= 输出目录配置 =========================
set(OUTPUT_ROOT ${CMAKE_SOURCE_DIR}/build_output)
# 按构建类型分目录（Debug/Release）
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_ROOT}/lib/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_ROOT}/lib/$<CONFIG>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_ROOT}/bin/$<CONFIG>)

# 适配多配置生成器（CLion 切换 Debug/Release 时生效）
foreach(OUTPUT_CONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUT_CONFIG} OUTPUT_CONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUT_CONFIG_UPPER} ${OUTPUT_ROOT}/bin/${OUTPUT_CONFIG})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUT_CONFIG_UPPER} ${OUTPUT_ROOT}/lib/${OUTPUT_CONFIG})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUT_CONFIG_UPPER} ${OUTPUT_ROOT}/lib/${OUTPUT_CONFIG})
endforeach()

# ========================= 源文件收集与过滤 =========================
# 收集所有 C 和 C++ 源文件
file(GLOB_RECURSE SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/*.c"
        "${CMAKE_SOURCE_DIR}/*.cpp"
        LIST_DIRECTORIES false  # 仅收集文件，不包含目录
)

# 过滤排除不需要的文件和目录（CLion 辅助文件、构建目录等）
list(FILTER SOURCE_FILES EXCLUDE REGEX
        "(/CMakeFiles/|/cmake-build-|/build_output/|/\\.idea/|/\\.git/|/test/|/docs/)"
)
list(FILTER SOURCE_FILES EXCLUDE REGEX "\\.(h|hpp|inc|txt|md|json)$")  # 仅保留源文件

# ========================= 生成可执行目标（核心修正）=========================
if(SOURCE_FILES)
    message(STATUS "找到 ${CMAKE_CURRENT_LIST_LENGTH} 个源文件，生成独立可执行目标：")
    foreach(SOURCE_FILE ${SOURCE_FILES})
        # 1. 提取文件名（不含路径和后缀）作为输出文件名
        get_filename_component(FILE_NAME_WE ${SOURCE_FILE} NAME_WE)

        # 2. 生成唯一目标名（解决不同目录下同名文件冲突）
        file(RELATIVE_PATH RELATIVE_PATH ${CMAKE_SOURCE_DIR} ${SOURCE_FILE})
        string(REPLACE "/" "_" TARGET_NAME ${RELATIVE_PATH})  # 路径分隔符替换为下划线

        # 3. 关键修正：每个目标仅绑定当前遍历的单个源文件（彻底避免 main 冲突）
        add_executable(${TARGET_NAME} ${SOURCE_FILE})

        # 4. 配置目标属性（优化 CLion 调试体验）
        set_target_properties(${TARGET_NAME} PROPERTIES
                OUTPUT_NAME ${FILE_NAME_WE}  # 输出文件名与源文件同名（如 reverse_pointer.exe）
                VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}  # 调试工作目录设为项目根目录
        )

        # 打印目标信息（方便查看绑定关系）
        message(STATUS "  - 目标: ${TARGET_NAME}")
        message(STATUS "    源文件: ${SOURCE_FILE}")
        message(STATUS "    输出路径: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${FILE_NAME_WE}.exe")
    endforeach()
else()
    message(WARNING "未找到任何 .c/.cpp 源文件！请检查项目结构")
endif()

# ========================= 编译选项（CLion 友好）=========================
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")  # MinGW/GCC/Clang 编译器
    # 通用警告选项（捕获潜在问题）
    add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter)

    # Debug 模式：保留完整调试信息，禁用优化（确保断点稳定）
    set(CMAKE_C_FLAGS_DEBUG "-g -O0 -ggdb")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -ggdb")

    # Release 模式：优化编译，减小体积
    set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
elseif(MSVC)  # Visual Studio 编译器
    add_compile_options(/W4 /wd4100)  # 启用警告，忽略未使用参数警告
    set(CMAKE_C_FLAGS_DEBUG "/Zi /Od /MDd")
    set(CMAKE_C_FLAGS_RELEASE "/O2 /DNDEBUG /MD")
    set(CMAKE_CXX_FLAGS_DEBUG "/Zi /Od /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG /MD")
endif()

# ========================= CLion 体验优化 =========================
# 排除冗余目录，避免 CLion 索引无关文件
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY CLION_EXCLUDE_DIRS
        ${OUTPUT_ROOT}      # 构建输出目录
        .idea               # CLion 配置目录
        cmake-build-*       # CLion 默认构建目录
)

# 自动生成 .gitignore，避免提交构建产物
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/.gitignore)
    file(WRITE ${CMAKE_SOURCE_DIR}/.gitignore
            "/build_output/\n/.idea/\n/cmake-build-*/\n*.exe\n*.o\n*.dll\n*.lib\n*.a\n"
    )
endif()