//
// Created by Liang on 2022/7/23.
//

#ifndef 栈与队列_FUNCTION_H
#define 栈与队列_FUNCTION_H

#endif //栈与队列_FUNCTION_H

#include "stdio.h"
#include "stdlib.h"
#include "iostream"

#define MAXSIZE 50

typedef char ElemType;
typedef char Node;

//二叉树
typedef struct BiTNode{
    Node data;//结点存的值是 字符型char
    struct BiTNode *left,*right;//左右子树
}BiTNode,*BiTree;
void initTree(BiTree &bt);
bool isBiTreeEmpty(BiTree bt);
//bool

//以下是栈的基础操作 非链栈
typedef struct Stack{
    int top;
    ElemType data[MAXSIZE];
//    struct Stack* next;//非链栈
}Stack,*pStack;
void initStack(pStack &s);
bool isStackEmpty(pStack s);
bool push(pStack &s,ElemType x);
bool pop(pStack &s,ElemType &x);
//以下是循环队的基础操作 非链队
typedef struct Queue{//非链队，怎么定义来着？ok
    ElemType data[MAXSIZE];
    int front,rear,curr;
    int length;
}Queue,*pQueue;
void initQueue(pQueue &q);
bool isQueueEmpty(pQueue q);
bool inQueue(pQueue &q,ElemType x);
bool outQueue(pQueue &q,ElemType &x);

//辅助队列，队内元素是 二叉树BiTNode
typedef struct btAssisQueue{
    BiTree btNode[MAXSIZE];
    int front,rear,curr;
    int length;
}btAssis,*pbtAssis;
void initbtAssis(pbtAssis &bt);
bool isbtAssisEmpty(pbtAssis bt);
bool inbtAssis(pbtAssis &bt,BiTree btx);
bool outbtAssis(pbtAssis &bt,BiTree &btx);