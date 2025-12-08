#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    int count[26];


    // 读取输入字符串（含空格、标点，以回车结束）
    fgets(str, sizeof(str), stdin);

    // 去除fgets读取的换行符
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    // 遍历字符串，统计英文字母出现次数
    for (int i = 0; i < len; i++) {
        char c = str[i];
        int idx = -1;  // 初始化索引为-1（非字母标记）

        // 手动判断是否为英文字母，并计算对应计数器索引
        if (c >= 'A' && c <= 'Z') {  // 大写字母：A-Z（ASCII 65-90）
            idx = c - 'A';  // 转换为0-25的索引（A→0，B→1，...，Z→25）
        } else if (c >= 'a' && c <= 'z') {  // 小写字母：a-z（ASCII 97-122）
            idx = c - 'a';  // 转换为0-25的索引（a→0，b→1，...，z→25）
        }

        // 仅处理英文字母（idx != -1 表示是字母）
        if (idx != -1) {
            count[idx]++;  // 对应字母计数+1

            // 检查是否首次达到3次，若是则输出原字符并退出
            if (count[idx] == 3) {
                printf("%c\n", c);
                return 0;
            }
        }
    }

    // 未找到出现3次的英文字母
    printf("NO\n");
    return 0;
}