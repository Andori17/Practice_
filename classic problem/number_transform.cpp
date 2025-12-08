#include<stdio.h>
int main(){
    int num=0;
    while (scanf("%d",&num)!=EOF) {
        int a,b,c;//abc分别代表个位，十，百，
        a=num%10;
        b=(num/10)%10;
        c=(num/100)%10;
        char *str_a[9]={"I","II","III","IV","V","VI","VII","VIII","IX"};
        char *str_b[9]={"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        char *str_c[9]={"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        if (c!=0)printf("%s",str_c[c-1]);
        if (b!=0)printf("%s",str_b[b-1]);
        if (a!=0)printf("%s",str_a[a-1]);
        printf("\n");
    }
return 0;
}


//
// Created by BanaWang on 2025/12/1.
//