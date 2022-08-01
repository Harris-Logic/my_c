//
// Created by Liang on 2022/7/30.
//数组 一个一个往后挪给插入者腾位置。插入位是j+1，j初值为i-1，插入者和a[j]比大小
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
    printf("\n");
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
//void insertSort(pnumstractive &a){//思路一
//    strxiabiao p=0,i=1;
//    while(i<a->length){
//        if(a->data[i]<a->data[i-1]){//从小到大排序
//            keytype tmp=a->data[i];
//            int j=i-1;
//            while(tmp<a->data[j]){
//                a->data[j+1]=a->data[j];
//                j--;
//                if(j<0)
//                    break;
//            }j++;
//            a->data[j]=tmp;//a[i]那里的人要放到 a[j+1]位置去，即插入 排序
//        }
//        i++;
//    }
//}
void insertSort(pnumstractive &a){//思路二
    strxiabiao p=0,i=1;
    while(i<a->length){//i未遍历到头
        keytype tmp=a->data[i];

        int j=i-1;
        while(true){//逐个往后挪一位 给新人腾一个地方
            if(a->data[j]>tmp)
                a->data[j+1]=a->data[j];
            else
                break;
            j--;
            if(j<0)
                break;
        }j++;

        a->data[j]=tmp;
        i++;
    }
}

int main(){
    pnumstractive a=(pnumstractive) calloc(1,sizeof (numstractive));
    ramdatainit(a,10);
    prinnumstr(a);

    insertSort(a);
    prinnumstr(a);
    return 0;
}