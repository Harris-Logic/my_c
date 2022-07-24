#include<stdio.h>

int main(){
    int i,total;
    
    for(i=0;i<100;i++){
        if(i%2==0) continue;
        total+=i;
    }
    

    return 0;
}

//判断核心是year%4==0&&year%100!=0||year%400==0，文科内容