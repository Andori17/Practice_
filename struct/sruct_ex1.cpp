#include <stdio.h>

// 定义职员结构体，封装所有相关信息
struct Employee {
    char name[10];   // 姓名（长度小于10）
    float base_salary;  // 基本工资
    float float_salary; // 浮动工资
    float expense;      // 支出
    float actual_salary;// 实发工资
};

int main() {
    int n;
    // 读取职员数量
    scanf("%d", &n);

    // 循环处理每位职员
    for (int i = 0; i < n; i++) {
        struct Employee emp;
        // 读取职员信息
        scanf("%s %f %f %f", emp.name, &emp.base_salary, &emp.float_salary, &emp.expense);
        // 计算实发工资
        emp.actual_salary = emp.base_salary + emp.float_salary - emp.expense;
        // 输出结果：保留2位小数
        printf("%s %.2f\n", emp.name, emp.actual_salary);
    }

    return 0;
}
//
// Created by BanaWang on 2025/12/8.
//