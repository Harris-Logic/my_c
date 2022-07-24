//
// Created by Liang on 2022/7/21.
//

#include "stdio.h"
int fbnqseq(int n){
    if(n==1) return 1;
    else if (n == 0) return 0;
    else { return fbnqseq(n - 1) + fbnqseq(n - 2); }
}
int main(){
    int x;
    while (scanf("%d",&x)!=EOF){//输入-1结束循环
        printf("斐波那契(%d)=%d",x, fbnqseq(x));
    }

//    printf("sfe");
    return 0;
}