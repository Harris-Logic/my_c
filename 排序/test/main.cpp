////
//// Created by Liang on 2022/9/22.
////
//
//#include "stdio.h"
//void swap(/*pnum &a,pnum &b*/int a,int b){
//    int m=a;a=b;b=m;
//    //    int m=*a;
////    *a=*b;
////    *b=m;
//}
//typedef int num,*pnum;
//
//int partition(int a[],int l,int h){
//    int k=l,i=l;
//    for(;i<h;i++){
//        if(a[i]<a[h]){
//            swap(a[i],a[k]);
//            k++;
//        }
//    }
//    swap(a[k],a[h]);
//    return k;
//}
//
//void quicksort(int a[],int l,int h){
//    if(l<h){
//        int pivot= partition(a,l,h);
//        quicksort(a,l,pivot-1);
//        quicksort(a,pivot+1,h);
//    }
//}
//
//int main(){
//    int a[]={4,1,6,5,8,3,7,9,2,1};
//
//    quicksort(a,0,9);
//    return 0;
//}