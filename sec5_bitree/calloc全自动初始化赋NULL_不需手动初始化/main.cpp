//
// Created by Liang on 2022/7/22.
//

#include "stdio.h"
#include "stdlib.h"
#include "iostream"
//作者 王道训练营 龙哥
typedef char BiElemType;
typedef struct BiTNode{
    BiElemType c;//c就是书籍上的data
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

typedef struct tag{
    BiTree p;//树的某一个结点的地址值
    struct tag *pnext;
}tag_t,*ptag_t;

//栈的相关数据结构
#define MaxSize 50
typedef BiTree ElemType;//ElemType是BiTree元素类型
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
typedef struct LinkNode{//链式队列结点
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{//链式队列
    LinkNode *front,*rear;
}LinkQueue;
void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,ElemType x);
bool DeQueue(LinkQueue &Q,ElemType &x);

int main() {
//    BiTree tree=(BiTree) calloc(1,sizeof (BiTree));//这里不对。
    BiTree tree=NULL;
    char c;
    ptag_t q_head=NULL,q_tail=NULL,q_curr=NULL;
    while(scanf("%c",&c)){//abcdefghijk
        if(c=='\n') break;
        BiTree tnew=(BiTree) calloc(1,sizeof (BiTNode));
//        BiTree tnew=(BiTree) calloc(1,sizeof (BiTree));//必须写成上面这句这样子，sizeof里不能是指针。只能是结构体变量名

        tnew->c=c;
//        ptag_t q_head=(ptag_t) calloc(1,sizeof (ptag_t));//这里有问题辅助队列初始化怎么搞？
//        ptag_t q_tail=q_head,q_curr=q_head;
//        ptag_t duiliejieidan=(ptag_t) calloc(1,sizeof (ptag_t));
        ptag_t duiliejieidan=(ptag_t) calloc(1,sizeof (tag_t));//每轮循环最初都要初始化一个新的队列节点(临时)
        duiliejieidan->p=tnew;
//        ptag_t q_tail=(ptag_t) calloc(1,sizeof (ptag_t));
//        ptag_t q_curr=(ptag_t) calloc(1,sizeof (ptag_t));
//这里是tree，和辅助队列的第一次初始化。不需要while前执行初始化，只需一个if==NULL{continue;} else即可
        if(tree==NULL){//这里有问题：tree初始化怎么弄？
            tree=tnew;
//            q_head->p=q_tail->p=q_curr->p=tnew;
            q_head=q_tail=q_curr=duiliejieidan;//(全局变量)辅助队列在这里第一次初始化。
            continue;
//            q_head->pnext=NULL;
        } else{//新的队列节点入队
            q_tail->pnext=duiliejieidan;
            q_tail=q_tail->pnext;
        }
//        if(tree->lchild==NULL){
        if(q_curr->p->lchild==NULL){
            q_curr->p->lchild=duiliejieidan->p;//duiliejieidan->p==tnew是同一个东西
//            tree->lchild=q_curr->p;
        } else if(q_curr->p->rchild==NULL){//if(tree->rchild==NULL){
            q_curr->p->rchild=duiliejieidan->p;//duiliejieidan->p==tnew是同一个东西
//            tree->rchild=q_curr->p;
            q_curr=q_curr->pnext;
        }
    }
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
