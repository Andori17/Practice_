#include <stdio.h>
void printArray(int *p, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}
void reverseArray(int *p, int size) {
    int *left = p;               // 指向数组首元素的指针
    int *right = p + size - 1;   // 指向数组尾元素的指针
    while (left < right) {
        // 交换两个指针指向的元素
        int temp = *left;
        *left = *right;
        *right = temp;
        // 移动指针向中间靠拢
        left++;
        right--;
    }
}
int main() {
    int n;
    printf("Enter array length:");
    scanf("%d",&n);
    int arr[n];
    int *p;
    p=arr;
    printf("Enter %d integers:  ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d",(p+i));
    }
    // 输出原始数组
    printArray(p, n);

    // 逆序数组
    reverseArray(p, n);

    // 输出逆序后的数组
    printArray(p, n);

    return 0;

}
//
// Created by BanaWang on 2025/11/18.
//