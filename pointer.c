#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;      // 修改指针指向的变量（外部的a和b）
    *y = temp;
}

int main() {
    int x = 10;
    int *ptr = &x;
    printf("ptr: %p\n",ptr);
    printf("address of ptr: %p\n",&ptr);
    printf("%d\n",*ptr);//解引用符*，上文中的*ptr则是声明ptr的指针变量身份
    int a = 1, b = 2;
    swap(&a, &b); // 传递a和b的地址
    printf("%d %d\n", a, b); // 输出2 1（成功交换）
    char*pc=NULL;
    int*pi=NULL;
    printf("%p %p\n",pc,pi);
    printf("%p %p",pc+1,pi+1);//不同类型的指针的步长不同

    return 0;
    return 0;
}





//
// Created by BanaWang on 2025/11/17.
//