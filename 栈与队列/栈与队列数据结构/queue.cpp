//
// Created by Liang on 2022/7/23.
//

#include "function.h"

void initQueue(pQueue &q){
    q=(pQueue) calloc(1,sizeof (Queue));
    q->front=q->rear=q->length=0;
}
bool isQueueEmpty(pQueue q){
    if(q->front==q->rear&&q->length==0) return true;//空true，非空false
    else return false;
}
bool inQueue(pQueue &q,ElemType x){
    if(q->length==MAXSIZE) return false;//满队，入队失败//q->rear+1%MAXSIZE==q->front|| 这个判断是多余的
    else{
        q->data[q->rear]=x;
        q->rear=(q->rear+1)%MAXSIZE;q->length++;//length存 队列里有几个人
        return true;
    }
}
bool outQueue(pQueue &q,ElemType &x){
    if(isQueueEmpty(q)) return false;//空队，出队失败
    else{
        x=q->data[q->front];
        q->data[q->front]=NULL;
        q->front=q->front+1%MAXSIZE;q->length--;
        return true;
    }
}