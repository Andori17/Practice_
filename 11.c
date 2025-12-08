//
// Created by BanaWang on 2025/10/29.
//
#include <stdio.h>

// 汉诺塔递归函数
void hanoi(int n, char a, char b, char c) {
    // 递归基：当只有一个盘子时
    if (n == 1) {
        printf("%c-->%c\n", a, b);  // 直接将盘子从a移动到b
        return;
    }

    // 递归步骤：
    // 1. 将n-1个盘子从a借助b移动到c
    hanoi(n - 1, a, c, b);

    // 2. 将最大的盘子从a移动到b
    printf("%c-->%c\n", a, b);

    // 3. 将n-1个盘子从c借助a移动到b
    hanoi(n - 1, c, b, a);
}

int main() {
    int n;
    scanf("%d", &n);  // 输入盘子个数

    hanoi(n, 'a', 'b', 'c');  // 调用汉诺塔函数

    return 0;
}
//wwewewe