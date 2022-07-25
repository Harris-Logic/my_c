//
// Created by Liang on 2022/7/23.
//

#include "function.h"
//前序遍历 abdhiejcfg
void preOrder(BiTree t){
    if(!isBiTreeEmpty(t)){
        putchar(t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}
//中序遍历 hdibjeafcg
void midOrder(BiTree t){
    if(!isBiTreeEmpty(t)){
        midOrder(t->left);
        putchar(t->data);
        midOrder(t->right);
    }
}
//后序遍历 hidjebfgca
void postOrder(BiTree t){
    if(!isBiTreeEmpty(t)){
        postOrder(t->left);
        postOrder(t->right);
        putchar(t->data);
    }
}
int main() {
//    pQueue q;
//    initQueue(q);
//
//    int x[]={2,3,4,5,6,98};
//    for(int i=0;i<MAXSIZE;i++) inQueue(q,x[i]);
//    int fanhui=0;
//    outQueue(q,fanhui);
//    bool qemp= isQueueEmpty(q);
//
//    pStack s;
//    initStack(s);
//
//    for(int i=0;i<MAXSIZE;i++) push(s,x[i]);
//    pop(s,fanhui);
//    bool semp= isStackEmpty(s);
    pbtAssis assis_que=NULL;
    initbtAssis(assis_que);
    BiTree t=NULL,newbt=NULL;
//    initTree(t);//

    char c;
    //abcdefghijkl
    while(scanf("%c",&c)){
        if(c=='\n') break;
        else{
            initTree(newbt);
            newbt->data=c;

            if(isBiTreeEmpty(t)){
//                t=newbt;
                inbtAssis(assis_que,newbt);
                t=newbt;
//                t=assis_que->btNode[assis_que->front];
                continue;
//                assis_que->front=assis_que->rear= assis_que->length=0;
//                assis_que->btNode[assis_que->rear]=newbt;
//                assis_que->rear=
                //                assis_que->data[assis_que.]
            } else{inbtAssis(assis_que,newbt);}
//                assis_que->data[assis_que->rear]=c;
//                assis_que->rear++;assis_que->length++
            if(!assis_que->btNode[assis_que->curr]->left){//顺序实现
                assis_que->btNode[assis_que->curr]->left=newbt;
            } else if(!assis_que->btNode[assis_que->curr]->right){
                assis_que->btNode[assis_que->curr]->right=newbt;
                assis_que->curr=assis_que->curr+1%MAXSIZE;
            }
        }
    }
    //前序遍历 abdhiejcfg
    printf("pre:\n");preOrder(t);
    //中序遍历 hdibjeafcg
    printf("\n");printf("mid:\n");midOrder(t);
    //后序遍历 hidjebfgca
    printf("\n");printf("post:\n");postOrder(t);


    printf("\n");
    return 0;
}
