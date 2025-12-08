#include<stdio.h>
#include<string.h>




int sum(char str[100])
{
    int sum = 0;
    int length = strlen(str);
    for(int i = 0;i < length; i++)
    {
        sum += str[i] - '0';
    }
    return sum;
}//
// Created by BanaWang on 2025/10/29.
//

int main(void)
{
    char num[100];
    scanf("%s", num);
printf("%d", sum(num));
return 0;
}