#include<stdio.h>

int main(){
    int a=0,i=0,n=0,tmp=0,b=0,k=0;

    scanf("%d",&n);

    // k=0;
    a=1;i=1;
    while(i<=n){
        a*=i;
        i++;
    }
    printf("%d",a);
    return 0;
}
// Description
// 某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。要求换正好40张，且每种票子至少一张。问：有几种换法？


// Input
// 无输入


// Output
// 一个数，表示共有多少种换法


