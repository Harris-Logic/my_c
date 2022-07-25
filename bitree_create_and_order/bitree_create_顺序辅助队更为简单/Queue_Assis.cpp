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

void iniAssisQueue(pAssis_Queue &q){
    q=(pAssis_Queue ) calloc(1,sizeof (Assis_Queue));
    q->front=q->rear=q->cur=q->length=0;
}
bool isAssisQueueEmpty(pAssis_Queue q){
    if(q->length==0) return true;//is Empty
    else return false;
}
bool EnAssisQueue(pAssis_Queue &q,pBiTree x){
    if(q->length==MAXSIZE) return false;

    q->bt[q->rear]=x;q->length++;
    q->rear++;//q->rear=q->rear+1%MAXSIZE;//这是循环队的写法
    return true;
}
bool DeAssisQueue(pAssis_Queue &q, pBiTree &x){
    if(isAssisQueueEmpty(q)) return false;//空队  出队失败

    x=q->bt[q->front];q->length--;
    q->front++;//步进//q->front=q->front+1%MAXSIZE;//这是循环队写法
    return true;
}