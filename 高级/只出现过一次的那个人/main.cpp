//
// Created by Liang on 2022/7/29.
//
#include "stdio.h"
#include "stdlib.h"
#define DATANUM 5 //一共输入5个人
#define MAXSIZE 1000 //数据规模
typedef int keytype;

int main(){
    keytype countstr[MAXSIZE]={0};//辅助数组 找出出现次数为1的那个人
    keytype str[DATANUM]={0};
    for(int i=0;i<DATANUM;i++){
        scanf("%d",&str[i]);
        countstr[str[i]]++;//此人出现次数 计数
    }
    int i=0;
    for(i=0;countstr[str[i]]!=1;i++);
    printf("%d",str[i]);

    return 0;
}