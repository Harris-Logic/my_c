//
// Created by Liang on 2022/7/26.
//不能子函数里声明 结构体数组，这样会占用过多的栈空间，导致runtime error

#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 20

typedef char ElemType;
typedef struct BiTree{
    ElemType node;
    struct BiTree *left,*right;
}BiTree,*pBiTree;
//void iniBiTree(pBiTree &t){
//    t=(pBiTree) calloc(1,sizeof (BiTree));
//    return ;
//}
bool isBiTreeEmpty(pBiTree t){
    if(t==NULL) return true;
    else if(t->node==NULL) return true;
    else return false;
}

typedef struct Assis_Queue{
    pBiTree bitree[MAXSIZE];
    int front,rear,cur,length;
}Assis_Queue,*pAssis_Queue;
//void iniAssisQueue(pAssis_Queue &q){
//    q=(pAssis_Queue) calloc(1,sizeof (Assis_Queue));
//    return;
//}
bool isAssisQueueEmpty(pAssis_Queue q){
    if(q==NULL) return true;//is Empty
    if(q->length==0) return true;
    else return false;
}
bool EnAssisQueue(pAssis_Queue &q,pBiTree x){
    if(q->length==MAXSIZE) return false;
    else{
        q->bitree[q->rear]=x;
        q->rear++;q->length++;
        return true;
    }
}
bool DeAssisQueue(pAssis_Queue &q,pBiTree &x){
    if(isAssisQueueEmpty(q)) return false;
    else{
        x=q->bitree[q->front];
        q->front++;q->length--;
        return true;
    }
}


void preOrder(pBiTree t){
    if(isBiTreeEmpty(t)) return;
    else{
        putchar(t->node);
        preOrder(t->left);
        preOrder(t->right);
        return;
    }
}

void inOrder(pBiTree t){
    if(isBiTreeEmpty(t)) return;
    else{
        inOrder(t->left);
        putchar(t->node);
        inOrder(t->right);
        return;
    }
}

void postOrder(pBiTree t){
    if(isBiTreeEmpty(t)) return;
    else{
        postOrder(t->left);
        postOrder(t->right);
        putchar(t->node);
        return;
    }
}

void levelOrder_notrecursion(pBiTree t){
    pAssis_Queue q;
    q=(pAssis_Queue) calloc(1,sizeof (Assis_Queue));
//    iniAssisQueue(q);
    EnAssisQueue(q,t);
    while (!isAssisQueueEmpty(q)){
        pBiTree x=NULL;
        DeAssisQueue(q,x);
        putchar(x->node);

        if(!isBiTreeEmpty(x->left)) EnAssisQueue(q,x->left);
        if(!isBiTreeEmpty(x->right)) EnAssisQueue(q,x->right);//不能是 else if
    }
    return;
}

int main(){
    pAssis_Queue q;
    q=(pAssis_Queue) calloc(1,sizeof (Assis_Queue));
//    iniAssisQueue(q);
    pBiTree t;
    t=(pBiTree) calloc(1,sizeof (BiTree));
//    iniBiTree(t);
    char c;
    while (scanf("%c",&c)){
        if(c=='\n') break;
        //when,c not \n
        pBiTree newbt=(pBiTree) calloc(1,sizeof (BiTree));
        newbt->node=c;
        EnAssisQueue(q,newbt);

        if(isBiTreeEmpty(t)){
            t=q->bitree[q->cur];
            continue;
        }
        if(isBiTreeEmpty(q->bitree[q->cur]->left)){
            q->bitree[q->cur]->left=newbt;
        }else if(isBiTreeEmpty(q->bitree[q->cur]->right)){
            q->bitree[q->cur]->right=newbt;
            q->cur++;
        }
    }
//    preOrder(t);
    inOrder(t);
    printf("\n");
    postOrder(t);
    printf("\n");
    levelOrder_notrecursion(t);

    return 0;
}
/*

abcdefghij
hdibjeafcg
hidjebfgca
abcdefghij
*/
