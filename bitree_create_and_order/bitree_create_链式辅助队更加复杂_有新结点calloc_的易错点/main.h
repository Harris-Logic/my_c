//
// Created by Liang on 2022/7/25.
//

#ifndef BITREE_CREATE_AND_ORDER_MAIN_H
#define BITREE_CREATE_AND_ORDER_MAIN_H

#endif //BITREE_CREATE_AND_ORDER_MAIN_H
#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 50
typedef char ElemType;

typedef struct BiTree{
    ElemType data;
    struct BiTree *left,*right;
}BiTree,*pBiTree;
void iniBiTree(pBiTree &t);
bool isBiTreeEmpty(pBiTree t);

//链式辅助队_队内节点
typedef struct Assis_Queue_Node{
    pBiTree bt;//链式辅助队里的结点 是二叉树结点指针
    struct Assis_Queue_Node *next;
}Assis_Queue_Node,*pAssis_Queue_Node;
//链式辅助队
typedef struct Assis_Queue{
    pAssis_Queue_Node front,rear,cur;
    int length;
}Assis_Queue,*pAssis_Queue;
//操作
void iniAssisQueue(pAssis_Queue &q);
bool isAssisQueueEmpty(pAssis_Queue q);
bool EnAssisQueue(pAssis_Queue &q,pBiTree x);
bool DeAssisQueue(pAssis_Queue &q,pBiTree &x);

