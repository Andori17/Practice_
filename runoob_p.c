#include <stdio.h>
#define LENGTH(array) (sizeof(array) / sizeof(array[0]))
int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array1[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = LENGTH(array);
    int length1=LENGTH(array1);
    printf("length: %d\n",length);
    printf("length1: %d\n",length1);
    int myArray[5] = {10, 20, 30, 40, 50};
    //在这里，myArray 是数组名，它表示整数类型的数组，包含 5 个元素。myArray 也代表着数组的地址，即第一个元素的地址。

    //数组名本身是一个常量指针，意味着它的值是不能被改变的，一旦确定，就不能再指向其他地方。

    //我们可以使用&运算符来获取数组的地址，如下所示：
    int *ptr = &myArray[0]; // 或者直接写作
    int *ptr1 = myArray;
    printf("ptr: %d\n",*ptr);
    printf("ptr1: %d\n",*ptr1);
    return 0;

}

//
// Created by BanaWang on 2025/11/17.
//