//
// Created by Liang on 2022/7/25.
//

#ifndef BITREE_CREATE_AND_ORDER_MAIN_H
#define BITREE_CREATE_AND_ORDER_MAIN_H

#endif //BITREE_CREATE_AND_ORDER_MAIN_H
#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 50

typedef char Elemtype;
//树
typedef struct BiTree{
    Elemtype data;//结点里是char、int型之类的东西
    struct BiTree* left;
    struct BiTree* right;
}BiTree,*pBiTree;
//队列
//辅助队列 及相关操作
typedef struct Queue_Assis{
    pBiTree bt[MAXSIZE];//树的数列,容纳MAXSIZE个树结点
    int front,rear,cur;//头尾下标以及当前工作下标
    int length;
}Queue_Assis,*pQueue_Assis;
void iniAssisQueue(pQueue_Assis &q);
bool isAssisQueueEmpty(pQueue_Assis q);
bool EnAssisQueue(pQueue_Assis &q,pBiTree x);
bool DeAssisQueue(pQueue_Assis &q, pBiTree &x);
