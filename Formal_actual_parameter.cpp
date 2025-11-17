#include<stdio.h>
int add(int a);
void swap(int *a,int *b);
int main() {
    int y=5;
    int x=add(y);
    printf("%d\n",x);
    void swap(int *x,int *y);
    printf("%d",y);
    return 0;
}
int add(int a) {
    a=9;
    return 6;
}
void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

//
// Created by BanaWang on 2025/11/2.
//