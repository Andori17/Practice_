#include<stdio.h>
struct {
    char name[20];
    int age;
}t,ti;
struct st {
    char name[20];
    int age;
};
typedef struct stu {
    char name[20];
    int age;
}Data;//非变量，Data的性质是类型
int main() {
    Data h={"BonDaswie",21};//根据typedef格式的结构体声明，h在此处具有了Data类型的变量结构体
}








//
// Created by BanaWang on 2025/12/8.
//