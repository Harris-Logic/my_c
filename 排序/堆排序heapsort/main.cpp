// Created by Liang on 2022/8/2.
// 堆排序可能考代码，往年考过
//大根堆 堆排序，选择排序的一种。 堆排序不是交换排序！
// 核心是HeapAdjust的反复调用。BuildMaxHeap函数从后向前for循环HeapAdjust，第一次是最后面的那个小二叉树。
// HeapSort先a.length个人的范围内 BuildMaxHeap一次，然后for，每次交换最后一个人和第一个人(让最大的人 去"已有序的序列"里)，
// 然后，减少一个人的范围循环BuildMaxHeap。知道人数范围减少至0
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
void heapadjust(pElemType &a,strxiabiao k,listlength length){//好牛逼的写法，很容易理解。虽然不够考研
    strxiabiao dad=k,son=dad*2+1;//son取左孩子下标
//    ElemType tmp=a[dad];//不需要这个王道的逻辑，更容易理解的代码
    while(1){
        if(son>length-1) break;//length-1是最后一个元素 son越界
        if(son<0) break;
        //下面这两个判断决定 是大根堆还是小根堆
        if(son+1<length && a[son]<a[son+1])//取左右孩子里 较大的那个
            son++;
        if(a[dad]>a[son])//爹比孩子大，符合大根堆 break
            break;
        else{
            swap(a[dad],a[son]);
            //a[dad]=a[son];//dad变son，下沉
            dad=son;son=dad*2+1;//下沉，调整下面的子树
        }
//        son*=2;
    }
//    a[dad]=tmp;
}
void buildmaxheap(pnumstractive &a,listlength length){
    //末尾成员号为length-1，除以二是他的父亲节点
    for(int i=(length-1)/2;i>=0;i--){//必须从后往前建堆 建立大根堆 第一次是最后面那个小二叉树
        heapadjust(a->data,i,length);
    }
//    printf("buildmaxheap:");
//    prinnumstr(a);//大根堆建立没问题
}
void heapsort(pnumstractive &str){//大根堆排序 执行排序的函数
    buildmaxheap(str,str->length);
    strxiabiao i=str->length-1;
    while (1){
        if(i<0) break;
        swap(str->data[i],str->data[0]);
        buildmaxheap(str,i);//数列末尾那几个人 逐渐不承认为堆成员。末尾形成有序序列
        i--;
    }
}
listlength countNumStr(pElemType b){
    int i;
    for(i=0;b[i]!=NULL;i++);
    i--;
    return i;
}
int main(){
    ElemType b[]={44,53,52,73,87,82,12,14,25,33,36,47};
    pnumstractive a=(pnumstractive) calloc(1,sizeof (numstractive));
    ramdatainit(a,countNumStr(b));

    memcpy(a->data,b,sizeof (b));//经常忘记的语法。非常实用

//    a->length= countNumStr(b);
    prinnumstr(a);

    heapsort(a);
    prinnumstr(a);
//    printf("%d",1/2);
    return 0;
}