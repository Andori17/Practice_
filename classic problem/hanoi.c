//
// Created by BanaWang on 2025/10/29.
//hannoi 尝试
#include <stdio.h>
void hanoi(int n, char from, char to, char temp){
    if(n == 1){
        printf("%c to %c\n", from, to);
        return;}
    hanoi(n-1, from, temp, to);
    printf("%c to %c\n", from, to);
    hanoi(n-1, temp, to,from);
}
int main() {
int n;
printf("Enter the number of disks: ");
scanf("%d", &n);
hanoi(n, 'A', 'B', 'C');
return 0;
}