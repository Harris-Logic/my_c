//
// Created by Liang on 2022/7/22.
//

#ifndef SEC5_BITREE_HAVEFUN_H
#define SEC5_BITREE_HAVEFUN_H

#endif //SEC5_BITREE_HAVEFUN_H
#include <stdio.h>
#include <stdlib.h>
//作者 王道训练营 龙哥
typedef char BiElemType;
typedef struct BiTNode{
    BiElemType c;//c就是书籍上的data
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;//树节点：data+左孩子(指针)+右孩子(指针)

typedef struct tag{//这玩意儿干啥用的，不是很理解->这就是层次建树所借助的队列(会申请3个指针来控制队列：phead,ptail,pcur  phead->ptail 局部操作即根左右)
    BiTree p;//树的某一个结点的地址值
    struct tag *pnext;
}tag_t,*ptag_t;//队列结点结构是 树节点(指针)+队列next节点(指针)

//栈的相关数据结构
#define MaxSize 50
typedef BiTree ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;
void InitStack(SqStack &S);
bool StackEmpty(SqStack &S);
bool Push(SqStack &S,ElemType x);
bool Pop(SqStack &S,ElemType &x);
bool GetTop(SqStack &S,ElemType &x);
//队列的相关数据结构
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;
void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,ElemType x);
bool DeQueue(LinkQueue &Q,ElemType &x);
