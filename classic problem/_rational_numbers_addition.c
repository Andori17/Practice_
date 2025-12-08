#include <stdio.h>

// 欧几里得算法求最大公约数（GCD）
int gcd(int a, int b) {
    // 确保a >= b，若b为0则返回a；否则递归求b和a%b的GCD
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int a1, b1, a2, b2;
    // 读取输入的两个分数：a1/b1 a2/b2
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);

    // 步骤1：计算通分后的分子和分母
    int sum_num = a1 * b2 + a2 * b1;  // 和的分子
    int sum_den = b1 * b2;            // 和的分母

    // 步骤2：求分子和分母的最大公约数，用于约分
    int common_divisor = gcd(sum_num, sum_den);

    // 步骤3：化简为最简分数
    int final_num = sum_num / common_divisor;   // 最简分子
    int final_den = sum_den / common_divisor;   // 最简分母

    // 步骤4：按格式输出
    if (final_den == 1) {
        // 分母为1时，只输出分子
        printf("%d\n", final_num);
    } else {
        // 否则输出 分子/分母
        printf("%d/%d\n", final_num, final_den);
    }

    return 0;
}
//
// Created by BanaWang on 2025/12/8.
//