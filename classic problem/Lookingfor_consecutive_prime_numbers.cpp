#include<stdio.h>
#include<math.h>
#include <string.h>
// #include <stdbool.h>
bool is_prime(int n) {
    if(n<=1) {return false;}
    if(n==2) {return true;}
    if(n%2==0) {return false;}
    int limit = sqrt(n);
    if (n>=3) {
        for (int i=3;i<=limit;i+=2) {
            if (n%i==0) {return false; }
        }
    }
    return true;
}

int main() {
    int L,K;
    char N[1001];
    scanf("%d %d",&L,&K);
    scanf("%s",N);

    // 遍历所有可能的K位连续子串
    for (int i = 0; i <= L - K; i++) {
        // 提取长度为K的子串
        char substring[11];  // K < 10，所以最多10位
        strncpy(substring, N + i, K);
        substring[K] = '\0';
        // 将子串转换为长整型
        int num = 0;
        for (int j = 0; j < K; j++) {
            num = num * 10 + (substring[j] - '0');
        }

        if (is_prime(num)) {
            printf("%s\n", substring);
            return 0;
        }
    }
    printf("404\n");
    return 0;
}











//
// Created by BanaWang on 2025/10/30.
//