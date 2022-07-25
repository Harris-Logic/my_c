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
void iniBiTree(pBiTree &bt);
bool isBiTreeEmpty(pBiTree bt);

//队列
//辅助队列 及相关操作
//typedef struct Queue_Assis_Node{//顺序实现就不需要区分队列和队列结点了。
//    pBiTree bt[MAXSIZE];
//    struct Queue_Assis_Node ;
//
//}Queue_Assis_Node,*pQueue_Assis_Node;
typedef struct Assis_Queue{
    pBiTree bt[MAXSIZE];//树的数列,容纳MAXSIZE个树结点//队列中的树数组成员 就是队列结点
    int front,rear,cur;//头尾下标以及当前工作下标 指示队列结点
    int length;
}Assis_Queue,*pAssis_Queue;
void iniAssisQueue(pAssis_Queue &q);
bool isAssisQueueEmpty(pAssis_Queue q);
bool EnAssisQueue(pAssis_Queue &q,pBiTree x);
bool DeAssisQueue(pAssis_Queue &q, pBiTree &x);
