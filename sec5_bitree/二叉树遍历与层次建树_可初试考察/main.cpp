#include "function.h"

//递归实现
//前序遍历 abdhiejcfg
void preOrder(BiTree p){
    if(p!=NULL){
        putchar(p->c);//等价于visit函数。根左右
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
//中序遍历 hdibjeafcg
void InOrder(BiTree p){
    if(p!=NULL){
        InOrder(p->lchild);
        putchar(p->c);//左根右
        InOrder(p->rchild);
    }
}
//后序遍历 hidjebfgca
void PostOrder(BiTree p){
    if(p!=NULL){
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        putchar(p->c);
    }
}
//中序遍历非递归，非递归执行效率更高，考的概率很低
void InOrder2(BiTree T){
    SqStack S;
    InitStack(S);BiTree p=T;
    while(p||!StackEmpty(S)){//逻辑或||
        if(p){
            Push(S,p);
            p=p->lchild;
        }else{
            Pop(S,p);putchar(p->c);
            p=p->rchild;
        }
    }
}
//层次遍历,广度优先遍历
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);//树根入队
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        putchar(p->c);
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
    }
}
//《王道C督学营》课程
//二叉树的建树（层次建树），前序、中序、后序遍历、中序非递归遍历、层次遍历
int main(){
    BiTree pnew;
    int i,j,pos;
    char c;
    BiTree tree=NULL;//树根
    ptag_t phead=NULL,ptail=NULL,listpnew,pcur;//phead就是队列头，ptail就是队列尾

    while(scanf("%c",&c)!=EOF){//abcdefghij
        if(c=='\n'){
            break;
        }
        pnew=(BiTree)calloc(1,sizeof(BiTNode));//pnew是树节点(指针) calloc申请空间并对空间进行初始化，赋值为0
        pnew->c=c;//数据放进去
        listpnew=(ptag_t)calloc(1,sizeof(tag_t));//listpnew是队列节点(指针) 给队列结点申请空间
        listpnew->p=pnew;//pnew成为队列中的一个结点
        if(NULL==tree){//借助队列，层次建树 tree空时，这个操作是第一个结点进树，此结点为根
            tree=pnew;//树的根
            phead=listpnew;//队列头
            ptail=listpnew;//队列尾
            pcur=listpnew;
            continue;//借助这个continue，本if{里面的东西只会执行一次，且单独执行，不执行后续代码。相当于初始化，不必多写一个scanf，唯一一个scanf可以进循环}
        }else{
            ptail->pnext=listpnew;//新结点放入链表，通过尾插法
            ptail=listpnew;//ptail指向队列尾部
        }//pcur始终指向要插入的结点的位置
        if(NULL==pcur->p->lchild){//如何把新结点放入树:pcur(当前树节点的左)的树节点的左孩子空，则将pnew放入左孩子
            pcur->p->lchild=pnew;//把新结点放到要插入结点的左边
        }else if(NULL==pcur->p->rchild){
            pcur->p->rchild=pnew;//把新结点放到要插入结点的右边
            pcur=pcur->pnext;//左右都放了结点后，pcur指向队列的下一个
        }
    }
    printf("--------前序遍历----------\n");
    preOrder(tree);
    printf("\n--------中序遍历------------\n");
    InOrder(tree);
    printf("\n--------后序遍历------------\n");
    PostOrder(tree);
    printf("\n--------中序遍历非递归------\n");//重要性低
    InOrder2(tree);
    printf("\n--------层次遍历-----------\n");
    LevelOrder(tree);

    printf("\n");
//    system("pause");
    return 0;
} 