//
// Created by Liang on 2022/7/26.
//

#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 50

typedef char ElemType;
typedef struct BiTree{
    ElemType node;
    struct BiTree *left,*right;
}BiTree,*pBiTree;
void iniBiTree(pBiTree &t){
    t=(pBiTree) calloc(1,sizeof (BiTree));

}
bool isEmptyBiTree(pBiTree t){
    if(t==NULL) return true;
    else if(t->node==NULL) return true;
    else return false;
}

typedef struct Assis_Queue{
    pBiTree bitree[MAXSIZE];
    int front,rear,cur,length;
}Assis_Queue,*pAssis_Queue;
void iniAssisQueue(pAssis_Queue &q){
    q=(pAssis_Queue) calloc(1,sizeof (Assis_Queue));

}
bool isEmptyAssisQueue(pAssis_Queue q){
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
    if(isEmptyAssisQueue(q)) return false;
    else{
        x=q->bitree[q->front];
        q->front++;q->length--;
        return true;
    }
}


void preOrder(pBiTree t){
    if(isEmptyBiTree(t)) return;
    else{
        putchar(t->node);
        preOrder(t->left);
        preOrder(t->right);
    }
}
int main(){
    pAssis_Queue q;
    iniAssisQueue(q);
    pBiTree t;
    iniBiTree(t);
    char c;
    while (scanf("%c",&c)){
        if(c=='\n') break;
        //when,c not \n
        pBiTree newbt=(pBiTree) calloc(1,sizeof (BiTree));
        newbt->node=c;
        EnAssisQueue(q,newbt);

        if(isEmptyBiTree(t)){
            t=q->bitree[q->cur];
            continue;
        }
        if(isEmptyBiTree(q->bitree[q->cur]->left)){
            q->bitree[q->cur]->left=newbt;
        }else if(isEmptyBiTree(q->bitree[q->cur]->right)){
            q->bitree[q->cur]->right=newbt;
            q->cur++;
        }
    }
    preOrder(t);
    return 0;
}