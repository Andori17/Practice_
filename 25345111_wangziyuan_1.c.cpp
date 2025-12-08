#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int b,a,c,n=0,wh=0,wc=0;
    scanf("%d",&n);
    do {b = rand() % 3;
        scanf("%d",&a);
        c=a-b;
        if(c==1||c==-2) {
            wh++;
            printf("P:%d C:%d Player Wins (P:%d C:%d)\n",a,b,wh,wc);
        }
        else if(c==0) {
            printf("P:%d C:%d Draw (P:%d C:%d)\n",a,b,wh,wc);
        }
        else {
            wc++;
            printf("P:%d C:%d Computer Wins (P:%d C:%d)\n",a,b,wh,wc);
        }
    }while(wh<n+1&&wc<n+1);
    if (wh > wc) {
        printf("Final Winner: Player\n");
    } else {
        printf("Final Winner: Computer\n");
    }
return 0;
}
//
// Created by BanaWang on 2025/9/9.
//