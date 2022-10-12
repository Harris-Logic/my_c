//
// Created by Liang on 2022/9/22.
//
//

#include "stdio.h"

int count_numstr(int a[]){
    int i=0;
    for(i=0;a[i]!=NULL;i++) ;
    i--;
    return i;
}
void swap(/*pnum &a,pnum &b*/int a,int b){
    int m=a;a=b;b=m;
    //    int m=*a;
//    *a=*b;
//    *b=m;
}
void heapadjust(int a[],int j,int length){
    int dad=j,son=2*dad+1;
    while(1){
        if(son+1>length) break;
        if(son+1<length&& a[son]<a[son+1]) son++;//
        if(a[dad]<a[son]) {
            swap(a[son], a[dad]);
            dad = son;
            son = 2 * dad + 1;
        } else if(a[dad]>=a[son]) break;
    }
}
void heapbuild(int a[],int length){
    for(int i=(length-1)/2;i>0;i--){
        heapadjust(a,i,length);
    }
}


int main(){
    int a[]={5,3,6,7,3,10,8,2,1,4,9};
    heapbuild(a, count_numstr(a));

    return 0;
}