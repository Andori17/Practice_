#include<stdio.h>
struct student{
    char num[6];
    char name[11];
    int a;
    int b;
    int c;
    int total;
};
int main(){
    int n;
    struct student best;
    best.total=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        struct student current;
        scanf("%s %s %d %d %d",current.num,current.name,&current.a,&current.b,&current.c);
        current.total=current.a+current.b+current.c;
        if(current.total>best.total){
            best=current;
        }
    }
    printf("%s %s %d\n", best.name, best.num, best.total);

    return 0;
}
//
// Created by BanaWang on 2025/12/8.
//输入样例00001 huanglan 78 83 75
