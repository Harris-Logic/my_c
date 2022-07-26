//
// Created by Liang on 2022/7/25.
//

#include "main.h"

void preOrder(pBiTree t){
    if(!isBiTreeEmpty(t)){
        putchar(t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

int main(){
    pBiTree t=NULL;//树的初始化必须是NULL，不能iniBiTree//其实是可以的，tree判空逻辑需要第一层和第二层，以免非法访问NULL指针
    iniBiTree(t);
    pAssis_Queue aq;
    iniAssisQueue(aq);

    char c;
    while(scanf("%c",&c)){
        if(c=='\n') break;//输入回车时离开循环

        pBiTree newBiTreeNode;
        iniBiTree(newBiTreeNode);
        newBiTreeNode->data=c;
        //用c建立的新BiTree节点 直接入链式辅助队.否则front和cur的next连不住接下来的所有节点
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
    preOrder(t);

    return 0;
}