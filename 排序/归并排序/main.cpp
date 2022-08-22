//
// Created by Liang on 2022/7/28.
//

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef int ElemType,*pElemType;
typedef int keytype,*pkeytype;
typedef int listlength;
typedef int strxiabiao;
typedef struct numstractive{
    keytype *data;//这样，回避 在结构体中声明 大量数组空间，挤占main栈空间造成runtime error
    listlength length;//动态数组成员数
}numstractive,*pnumstractive;
void swap(ElemType &a,ElemType &b){
    ElemType tmp;
    tmp=a;
    a=b;
    b=tmp;
}
void prinnumstr(pnumstractive a){
    for(int i=0;i<a->length;i++)
        printf("%d ",a->data[i]);
    printf("\n");
}
void ramdatainit(pnumstractive &a,listlength len){//初始化函数
    a->length=len;
    a->data=(pkeytype)calloc(a->length,sizeof (keytype));
//    int i;
    srand(time(NULL));
    for(int i=0;i<a->length;i++){
        a->data[i]=rand()%100;
    }
}
#define DATASIZE 10
//
//typedef int ElemType;
//typedef int Strlength;
//typedef struct ElemStr{
//    Strlength length;
//    struct ElemStr* data;
//}ElemStr,*pElemStr;
void guibingsort(pnumstractive &array,int &xia,int &zhong,int &shang){
    if(array->data[xia])
    if(xia<shang){
        guibingsort(array,)
    }
//    buchang*=2;
//    guibingsort(array,shang,xia,buchang);

}

int main(){
    int a[DATASIZE];
    for(int i=0;i<DATASIZE;i++){
        scanf("%d",&a[i]);
    }
    guibingsort;

    return 0;
}