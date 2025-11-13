#include <math.h>
#include <stdio.h>
int main()
{
    float a, b, c, d, x1, x2, rp, ip;
    scanf_s("%f%f%f", &a, &b, &c);
    printf("the equation is: %.2fx^2 + %.2fx + %.2f = 0\n", a, b, c); // 输出方程具体形式
    if (fabs(a) < 1e-6) printf("is not quadratic\n");
    else
    {
        d = b * b - 4 * a * c;
        if (fabs(d) <= 1e-6)
        {
            printf("has two equal roots:\n");
            printf("x1=x2=%8.4f\n", -b / (2 * a));
        }
        else if (d > 1e-6)
        {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            printf("has two real roots:\n");
            printf("x1=%8.4f, x2=%8.4f\n", x1, x2);
        }
        else
        {
            rp = -b / (2 * a);
            ip = sqrt(-d) / (2 * a);
            printf("has two complex roots:\n");
            printf("x1=%8.4f+%8.4fi\n", rp, ip);
            printf("x2=%8.4f-%8.4fi\n", rp, ip);
        }
    }
    return 0;
}
//
// Created by BanaWang on 2025/10/31.
//