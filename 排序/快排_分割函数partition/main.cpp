//
// Created by Liang on 2022/7/30.
//快排 交换排序算法
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
    for(int i=0;i<a->length;i++)
        printf("%d ",a->data[i]);

}
void ramdatainit(pnumstractive &a,listlength len){
    a->length=len;
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
int partition(pnumstractive &a,strxiabiao l,strxiabiao h){//快排核心，快排分割函数 从小到大
//    if(l>=h) return NULL;
    int k=l,i=l;
    for(i=l;i<h;i++){
        if(a->data[h]>a->data[i]){//暗示 以h即最后一个成员 作为分割者。从小到大排
            swap(a->data[k],a->data[i]);
            k++;//k往后找，k所在的位置 已经被 分割者预定了
        }
    }
    swap(a->data[k],a->data[h]);//循环结束，交换分割者a.data[h]到位置k
    return k;
}
void quicksort(pnumstractive &a,strxiabiao l,strxiabiao h){//写成两个函数 要好理解好想一些
    strxiabiao pivot;//分割者 定义
    if(l<h){//l尚小等于h
        pivot= partition(a,l,h);
        quicksort(a,l,pivot-1);
        quicksort(a,pivot+1,h);
    }

}

int main(){
    pnumstractive a=(pnumstractive) calloc(1,sizeof (numstractive));
    ramdatainit(a,10);

    keytype A[10]={ 64, 94, 95, 79, 69, 84, 18, 12, 12 ,78};
    memcpy(a->data,A,sizeof (A));
    prinnumstr(a);printf("\n");
    quicksort(a,0,a->length-1);
    prinnumstr(a);printf("\n");
    prinnumstr(a);
    return 0;
}

