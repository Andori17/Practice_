#include<stdio.h>
#include<string.h>
void deletn(char *str);
void transform(char *str);
int main() {
    char str_a[9999];
    char str_b[9999];
    fgets(str_a, 9999, stdin);
    fgets(str_b, 9999, stdin);
    deletn(str_a);
    deletn(str_b);
    transform(str_a);
    transform(str_b);
    if(strcmp(str_a, str_b) == 0) {
printf("YES\n");}
else {printf("NO\n");}
return 0;
}
void transform(char *str) {
    char temp[9999];  // 临时字符串缓冲区（大小与原字符串一致，足够存储）
    int i = 0;        // 原字符串遍历索引（读指针）
    int j = 0;        // 临时字符串写入索引（写指针）

    // 1. 遍历原字符串，整理字符存入临时字符串
    while (str[i] != '\0') {
        // 大写转小写后存入临时字符串
        if (str[i] >= 'A' && str[i] <= 'Z') {
            temp[j] = str[i] - 'A' + 'a';
            j++;
        }
        // 非空格字符直接存入临时字符串
        else if (str[i] != ' ') {
            temp[j] = str[i];
            j++;
        }
        // 空格字符：直接跳过，不存入临时字符串

        i++;  // 原字符串索引始终后移
    }
    temp[j] = '\0';  // 给临时字符串添加结束符（关键）

    // 2. 将整理后的临时字符串复制回原字符串（覆盖原内容）
    strcpy(str, temp);
}


    void deletn(char *str) {
        int len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--;
        }
    }

//
// Created by BanaWang on 2025/12/1.
//