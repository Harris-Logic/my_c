//
// Created by Liang on 2022/7/30.
//数组 一个一个往后挪给插入者腾位置。插入位是j+1，j初值为i-1，插入者和a[j]比大小
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef int ElemType;
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
//折半查找 插入排序
void MidInsertSort(ElemType A[],int n)
{
    int i,j,low,high,mid;
    for(i=2;i<=n;i++)
    {
        A[0]=A[i];
        low=1;high=i-1;
        while(low<=high)//先通过二分查找找到待插入位置
        {
            mid=(low+high)/2;
            if(A[mid]>A[0])
                high=mid-1;
            else
                low=mid+1;
        }
        for(j=i-1;j>=high+1;--j)
            A[j+1]=A[j];
        A[high+1]=A[0];
    }
}
//希尔排序 和你的代碼不兼容
//多轮插入排序，考的概率很低，因为编写起来复杂，同时效率并不如快排，堆排
void ShellSort(ElemType A[],int n){
    int dk,i,j;
    // 73 29 74 51 29 90 37 48 72 54 83
    for(dk=n/2;dk>=1;dk=dk/2){//步长变化
        for(i=dk+1;i<=n;++i){//以dk为步长进行插入排序
            if(A[i]<A[i-dk]){
                A[0]=A[i];
                for(j=i-dk;j>0&&A[0]<A[j];j=j-dk)
                    A[j+dk]=A[j];
                A[j+dk]=A[0];
            }
        }
    }
}

int main(){
    pnumstractive a=(pnumstractive) calloc(1,sizeof (numstractive));
    ramdatainit(a,10);
    
    prinnumstr(a);
    ShellSort(a->data,10);
    prinnumstr(a);
    insertSort(a);
    prinnumstr(a);
    return 0;
}
