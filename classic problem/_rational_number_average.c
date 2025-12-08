#include <stdio.h>
#include <stdlib.h>  // 用于abs()函数，处理负数的绝对值

// 欧几里得算法求最大公约数（GCD），参数为非负整数
int gcd(int a, int b) {
    a = abs(a);  // 确保a为非负
    b = abs(b);  // 确保b为非负
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 有理数加法函数：sum_num/sum_den += a/b，结果仍存储在sum_num/sum_den中，并约分
void add_fraction(int *sum_num, int *sum_den, int a, int b) {
    // 通分求和：sum_num/sum_den + a/b = (sum_num*b + a*sum_den) / (sum_den*b)
    int new_num = *sum_num * b + a * *sum_den;
    int new_den = *sum_den * b;

    // 求最大公约数，约分
    int common = gcd(new_num, new_den);
    *sum_num = new_num / common;
    *sum_den = new_den / common;
}

int main() {
    int n;
    // 读取有理数个数
    scanf("%d", &n);

    // 初始化总和：0/1
    int total_num = 0;
    int total_den = 1;

    // 循环读取并累加每个分数
    for (int i = 0; i < n; i++) {
        int a, b;
        // 读取单个分数（支持负数，如-5/10）
        scanf("%d/%d", &a, &b);
        // 累加当前分数到总和
        add_fraction(&total_num, &total_den, a, b);
    }

    // 计算平均值：总和 / n = total_num / (total_den * n)
    int avg_num = total_num;
    int avg_den = total_den * n;

    // 约分平均值
    int common = gcd(avg_num, avg_den);
    avg_num /= common;
    avg_den /= common;

    // 按格式输出
    if (avg_den == 1) {
        printf("%d\n", avg_num);
    } else {
        printf("%d/%d\n", avg_num, avg_den);
    }

    return 0;
}
//
// Created by BanaWang on 2025/12/8.
//