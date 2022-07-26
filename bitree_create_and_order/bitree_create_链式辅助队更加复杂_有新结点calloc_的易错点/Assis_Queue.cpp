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
void iniAssisQueueNode(pAssis_Queue_Node &qnode){
    qnode=(pAssis_Queue_Node) calloc(1,sizeof (Assis_Queue_Node));

}
void iniAssisQueue(pAssis_Queue &q){//有坑！！！得让front,cur,rear的next连上
    q=(pAssis_Queue) calloc(1,sizeof (Assis_Queue));
    q->length=0;
    iniAssisQueueNode(q->rear);
    q->cur=q->front=q->rear;
}
bool isAssisQueueEmpty(pAssis_Queue q){
    if(q->length==0) return true;//is Empty

    else return false;
}
bool EnAssisQueue(pAssis_Queue &q,pBiTree x){//有坑
    if(q->length==MAXSIZE) return false;//full，入队失败
//    iniAssisQueueNode(q->rear);
    q->rear->bt=x;
    iniAssisQueueNode(q->rear->next);//坑！！！只要有新节点(指针) 要入队，必须calloc
    q->rear=q->rear->next;
    q->length++;
}
bool DeAssisQueue(pAssis_Queue &q,pBiTree &x){
    if(isAssisQueueEmpty(q)) return false;//is Empty出队失败

    x=q->front->bt;
    pAssis_Queue_Node linshi=q->front;

    q->front=q->front->next;q->length--;
    free(linshi);//出队要free，入队要calloc
}