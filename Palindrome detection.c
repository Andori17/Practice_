#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    int len = strlen(str);
    int left=0,right=len-2;
    int is_Palindrome=1;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';  // 用字符串结束符替换换行符
    }
    while(left<right) {
        if(str[left]!=str[right]) {
            is_Palindrome=0;
            break;
        }
        left++,right--;
    }
    if(is_Palindrome) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
        return 0;
}


// Created by BanaWang on 2025/12/1.
//