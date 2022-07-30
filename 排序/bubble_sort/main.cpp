//
// Created by Liang on 2022/7/30.
//

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef int keytype,*pkeytype;
typedef int listlength;
typedef struct numstractive{
    keytype *data;//这样，回避 在结构体中声明 大量数组空间，挤占main栈空间造成runtime error
    listlength length;//动态数组成员数
}numstractive,*pnumstractive;
void prinnumstr(numstractive a){
    for(int i=0;i<a.length-1;i++)
        printf("%d ",a.data[i]);
    printf("\n");
}
void ramdatainit(numstractive &a,listlength len){
    a.length=len+1;
    a.data=(pkeytype)calloc(a.length,sizeof (keytype));
//    int i;
    srand(time(NULL));
    for(int i=0;i<a.length;i++){
        a.data[i]=rand()%100;
    }
}
void bubblesort(numstractive &a){//从小到大排序
    bool flag= false;
    for(int i=0;i<a.length;i++){//i保存的是已经抵达终点的 那个最新的成员
        flag= false;/*flag初始化为false*/
        for(int j=a.length-1;j>i;j--){
            if(a.data[j]<a.data[j-1]){//后面更小，就交换
                keytype tmp=a.data[j];
                a.data[j]=a.data[j-1];
                a.data[j-1]=tmp;
                flag= true;//标记 本轮发生交换
            }
        }
        if(flag== false) break;//循环结束后，未发生交换，说明已排列完成
    }
}

int main(){
    numstractive a;
    keytype A[10]={ 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78};
    ramdatainit(a,10);
//    memcpy(a.data,A,sizeof (A));
    prinnumstr(a);
    bubblesort(a);
    prinnumstr(a);
    return 0;
}