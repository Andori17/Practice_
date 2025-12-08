#include <stdio.h>
#include <stdio.h>

int main() {
    char c;
    char word[21];  // 单个单词≤20字母，留1字节冗余
    char *p = word; // 指针p指向缓冲区起始位置（替代idx=0）

    // 逐字符读取输入（直到EOF）
    while ((c = getchar()) != EOF) {
        if (c != ' ') {  // 遇到单词字符：存入缓冲区，指针后移
            // 限制指针不越界（单词≤20字母，p最多指向word[20]）
            if (p < word + 20) {
                *p = c;  // 字符存入p指向的地址
                p++;     // 指针后移，准备存储下一个字符
            }
        } else {  // 遇到空格：处理当前单词（若有），输出空格
            if (p > word) {  // 指针在起始位置之后→缓冲区有单词（替代idx>0）
                // 反向遍历：从p-1（单词末尾）到word（起始）
                for (char *q = p - 1; q >= word; q--) {
                    putchar(*q);  // 输出q指向的字符
                }
                p = word;  // 指针重置为缓冲区起始（替代idx=0）
            }
            putchar(' ');  // 输出原空格
        }
    }

    // 处理最后一个单词（输入结束时，指针可能在起始位置之后）
    if (p > word) {
        for (char *q = p - 1; q >= word; q--) {
            putchar(*q);
        }
    }

    putchar(' ');  // 题目要求末尾带空格
    return 0;
}