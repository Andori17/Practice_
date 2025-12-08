#include <stdio.h>
#include<string.h>
int main() {
    char*p;
    p="acb";
    printf("%s\n",p);
    printf("%d\n",*p);
    printf("%c\n",*p);
    char buffer[100];
    printf("input:");
    if (fgets(buffer,100,stdin)!=NULL) {
        printf("confirm the input:");
        fputs(buffer,stdout);
    }
    else {
        printf("failed");
    }
    printf("\n%d\n",strlen(buffer));
    printf("%d\n",sizeof(buffer));
    strncat(buffer,"hello",5);
    fputs(buffer,stdout);
    return 0;
}

//
// Created by BanaWang on 2025/11/27.
//