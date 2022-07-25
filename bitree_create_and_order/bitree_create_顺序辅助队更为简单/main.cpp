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
int main() {
    pBiTree t;
    iniBiTree(t);
    pAssis_Queue aq;
    iniAssisQueue(aq);

    char c;
    while(scanf("%c",&c)){
        if(c=='\n') break;
        pBiTree newbitree;
        iniBiTree(newbitree);
        newbitree->data=c;
        EnAssisQueue(aq,newbitree);

        if(isBiTreeEmpty(t)){
            t=aq->bt[aq->cur];
            continue;
        }

        if(aq->bt[aq->cur]->left==NULL)
            aq->bt[aq->cur]->left=newbitree;
        else if(aq->bt[aq->cur]->right==NULL) {
            aq->bt[aq->cur]->right=newbitree;
            aq->cur++;
        }
    }
    preOrder(t);
    //    std::cout << "Hello, World!" << std::endl;
    return 0;
}

