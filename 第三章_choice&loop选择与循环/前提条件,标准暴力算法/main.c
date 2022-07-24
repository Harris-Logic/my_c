#include<stdio.h>

int main(){
    // int a=0,i=0,n=0,tmp=0,k=0;
    int money_10=1,money_5=1,money_2=1,money_1=1;
    int count=0;

    // while(money_10<10&&money_1<100&&money_2<50&&money_5<20){
        // money_10;
    while(money_10<10){
        while(money_5<20){
            while(money_2<50){
                while(money_1<100){
                    if((money_10*10+money_5*5+money_2*2+money_1*1)==100 && (money_10+money_5+money_2+money_1)==40 ) count++;
                    // printf("count=%d,1yuan*%d||",count,money_1);
                    money_1++;
                }
                money_2++;money_1=1;
            }
            money_5++;money_2=1;money_1=1;
        }
        money_10++;money_5=1;money_2=1;money_1=1;//每次增加一轮循环，都要初始化上一层的计数变量（易错点）
    }
        // if(money_10*10+money_5*5+money_2*2+money_1*1==100 && money_10+money_5+money_2+money_1==40 && money_10>0 && money_5>0 && money_2>0 && money_1>0 ) count++;
        // else money_1++;
    // }
    

    printf("%d",count);
    return 0;
}
// Description
// 某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。要求换正好40张，且每种票子至少一张。问：有几种换法？


// Input
// 无输入


// Output
// 一个数，表示共有多少种换法