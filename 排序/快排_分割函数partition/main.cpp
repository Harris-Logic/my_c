//
// Created by Liang on 2022/7/30.
//
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef int keytype,*pkeytype;
typedef int listlength;
typedef int strxiabiao;
typedef struct numstractive{
    keytype *data;//这样，回避 在结构体中声明 大量数组空间，挤占main栈空间造成runtime error
    listlength length;//动态数组成员数
}numstractive,*pnumstractive;
void prinnumstr(pnumstractive a){
    for(int i=0;i<a->length-1;i++)
        printf("%d ",a->data[i]);
    printf("\n");
}
void ramdatainit(pnumstractive &a,listlength len){
    a->length=len+1;
    a->data=(pkeytype)calloc(a->length,sizeof (keytype));
//    int i;
    srand(time(NULL));
    for(int i=0;i<a->length;i++){
        a->data[i]=rand()%100;
    }
}
void swap(keytype &a,keytype &b){//交换排序的基础动作，swap
    keytype tmp=a;
    a=b;
    b=tmp;
}
void partition(pnumstractive &a,strxiabiao l,strxiabiao h){//快排核心，快排分割函数 从小到大
    if(l>=h) return;
    int k=l,i=l;
    for(i=l;i<h-1;i++){
        if(a->data[k]>a->data[i])
            swap(a->data[k],a->data[i]);
    }
    swap(a->data[k],a->data[i+1]);//循环结束，交换分割者到位置k
    partition(a,l,k-1);
    partition(a,k+1,a->length);
}

int main(){
    pnumstractive a=(pnumstractive) calloc(1,sizeof (numstractive));
    ramdatainit(a,10);

    prinnumstr(a);
    partition(a,0,a->length);
    prinnumstr(a);
    return 0;
}

