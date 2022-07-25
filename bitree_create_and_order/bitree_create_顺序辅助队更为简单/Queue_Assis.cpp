//
// Created by Liang on 2022/7/25.
//

#include "main.h"

//辅助队列 及相关操作
//辅助队列数据结构如下
//typedef struct Queue_Assis{
//    pBiTree bt;//树的数列
//    int front,rear,cur;//头尾下标以及当前工作下标
//    int length;
//}Queue_Assis,*pQueue_Assis;

void iniAssisQueue(pQueue_Assis &q){
    q=(pQueue_Assis) calloc(1,sizeof (Queue_Assis));
    q->front=q->rear=q->cur=q->length=0;
}
bool isAssisQueueEmpty(pQueue_Assis q){
    if(q->length==0) return true;//is Empty
    else return false;
}
bool EnAssisQueue(pQueue_Assis &q,pBiTree x){
    if(q->length==MAXSIZE) return false;

    q->bt[q->rear]=x;q->length++;
    q->rear++;
    return true;
}
bool DeAssisQueue(pQueue_Assis &q, pBiTree &x){
    if(isAssisQueueEmpty(q)) return false;//空队  出队失败

    x=q->bt[q->front];q->length--;
    q->front++;//步进
    return true;
}