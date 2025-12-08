#include <stdio.h>

int main() {
    char ch;
    int count = 0;
    int in_word = 0;  // 标记是否在单词中，0为否，1为是

    while ((ch = getchar()) != '\n') {  // 逐字符读取直到换行
        if (ch != ' ') {  // 非空格字符
            if (in_word==0) {  // 新单词开始
                count++;
                in_word = 1;
            }
        } else {  // 空格字符，结束当前单词
            in_word = 0;
        }
    }

    printf("%d\n", count);
    return 0;
}

//
// Created by BanaWang on 2025/11/25.
//