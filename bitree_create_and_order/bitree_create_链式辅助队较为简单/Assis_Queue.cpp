//
// Created by Liang on 2022/7/25.
//
#include "main.h"

////链式辅助队_队内节点
//typedef struct Assis_Queue{
//    pBiTree bt;//链式辅助队里的结点 是二叉树结点指针
//    struct Assis_Queue *next;
//}Assis_Queue,*pAssis_Queue;

////链式辅助队
//typedef struct Assis_Queue{
//    pAssis_Queue_Node front,rear,cur;
//    int length;
//}Assis_Queue,*pAssis_Queue;

void iniAssisQueue(pAssis_Queue &q){
    q=(pAssis_Queue) calloc(1,sizeof (Assis_Queue));
    q->length=0;
    q->cur=q->front=q->rear=NULL;
}
bool isAssisQueueEmpty(pAssis_Queue q){
    if(q->length==0) return true;//is Empty

    else return false;
}
bool EnAssisQueue(pAssis_Queue &q,pBiTree x){
    if(q->length==MAXSIZE) return false;//full，入队失败

    q->rear->bt=x;
    q->rear=q->rear->next;q->length++;
}
bool DnAssisQueue(pAssis_Queue &q,pBiTree &x){
    if(isAssisQueueEmpty(q)) return false;//is Empty出队失败

    x=q->front->bt;
    q->front=q->front->next;q->length--;
}