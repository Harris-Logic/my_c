//
// Created by Liang on 2022/7/26.
//


#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 50
typedef char ElemType;

typedef struct BiTree{
    ElemType data;
    struct BiTree *left,*right;
}BiTree,*pBiTree;

//void iniBiTree(pBiTree &t){
//    t=(pBiTree) calloc(1,sizeof(BiTree));
// return;
//}
bool isBiTreeEmpty(pBiTree t){
    if(t==NULL) return true;//is Empty
    if(t->data==NULL) return true;
    else return false;
}

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


//void iniAssisQueueNode(pAssis_Queue_Node &qnode){
//    qnode=(pAssis_Queue_Node) calloc(1,sizeof (Assis_Queue_Node));
// return;
//}
//void iniAssisQueue(pAssis_Queue &q){//有坑！！！得让front,cur,rear的next连上//rear需要calloc。front,cur,rear都需要指向同一个指针rear
//    q=(pAssis_Queue) calloc(1,sizeof (Assis_Queue));
//   q->length=0;
//  iniAssisQueueNode(q->rear);
// q->cur=q->front=q->rear;
//return;
//}
bool isAssisQueueEmpty(pAssis_Queue q){
    if(q->length==0) return true;//is Empty

    else return false;
}
bool EnAssisQueue(pAssis_Queue &q,pBiTree x){//有坑
    if(q->length==MAXSIZE) return false;//full，入队失败

    q->rear->bt=x;
    q->rear->next=(pAssis_Queue_Node)calloc(1,sizeof(Assis_Queue_Node));
    //iniAssisQueueNode(q->rear->next);//坑！！！只要有新节点(指针) 要入队，必须calloc
    q->rear=q->rear->next;
    q->length++;
    return true;
}
bool DeAssisQueue(pAssis_Queue &q,pBiTree &x){
    if(isAssisQueueEmpty(q)) return false;//is Empty出队失败

    x=q->front->bt;
    pAssis_Queue_Node linshi=q->front;

    q->front=q->front->next;q->length--;
    free(linshi);//出队要free，入队要calloc
    return true;
}

void preOrder(pBiTree t){
    if(!isBiTreeEmpty(t)){
        putchar(t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
    return;
}
void inOrder(pBiTree t){
    if(!isBiTreeEmpty(t)){
        inOrder(t->left);
        putchar(t->data);
        inOrder(t->right);
    }
    return;
}
void postOrder(pBiTree t){
    if(!isBiTreeEmpty(t)){
        postOrder(t->left);
        postOrder(t->right);
        putchar(t->data);
    }
    return;
}
void levelOrder(pBiTree t){
    pAssis_Queue q;
    q=(pAssis_Queue)calloc(1,sizeof(Assis_Queue));
    q=(pAssis_Queue)calloc(1,sizeof(Assis_Queue));
    q->rear=(pAssis_Queue_Node) calloc(1,sizeof (Assis_Queue_Node));
    q->front=q->cur=q->rear;
    //iniAssisQueue(q);
    EnAssisQueue(q,t);
    while(!isAssisQueueEmpty(q)){
        pBiTree x=NULL;
        DeAssisQueue(q,x);
        putchar(x->data);
        if(!isBiTreeEmpty(x->left))
            EnAssisQueue(q,x->left);
        if(!isBiTreeEmpty(x->right))
            EnAssisQueue(q,x->right);
    }
    return;
}

int main(){
    pBiTree t=NULL;//树的初始化必须是NULL，不能iniBiTree//其实是可以的，tree判空逻辑需要第一层和第二层，以免非法访问NULL指针
    t=(pBiTree)calloc(1,sizeof(BiTree));
    //iniBiTree(t);
    pAssis_Queue aq;
    aq=(pAssis_Queue)calloc(1,sizeof(Assis_Queue));
    aq->rear=(pAssis_Queue_Node) calloc(1,sizeof (Assis_Queue_Node));
    aq->front=aq->cur=aq->rear;
//    iniAssisQueue(aq);

    char c;
    while(scanf("%c",&c)){
        if(c=='\n') break;//输入回车时离开循环

        pBiTree newBiTreeNode;
        newBiTreeNode=(pBiTree)calloc(1,sizeof(BiTree));
        //iniBiTree(newBiTreeNode);
        newBiTreeNode->data=c;

        EnAssisQueue(aq,newBiTreeNode);//这里，入队是有坑的。注意看iniAssisQueue的定义。以免非法访问NULL指针

        if(isBiTreeEmpty(t)){//树空，则进行一次初始化操作
            t=aq->cur->bt;//有坑！！！这里t最好指向队列工作指针 便于建立树
//            EnAssisQueue(aq,newBiTreeNode);
            continue;//意思是，这里面的代码只执行一遍，负责的是 初始化的工作
        }

        //接下来是树非空状态
        if(aq->cur->bt->left==NULL){//cur左孩子空吗？
            aq->cur->bt->left=newBiTreeNode;
        }else if(aq->cur->bt->right==NULL){//cur右孩子空吗？
            aq->cur->bt->right=newBiTreeNode;
            aq->cur=aq->cur->next;//辅助队列工作指针 步进
        }
    }

    inOrder(t);
    printf("\n");
    postOrder(t);
    printf("\n");
    levelOrder(t);
    return 0;
}
/*

abcdefghij
hdibjeafcg
hidjebfgca
abcdefghij
*/