//
// Created by Liang on 2022/7/23.
//

#include "function.h"

void initTree(BiTree &bt){
    bt=(BiTree) calloc(1,sizeof (BiTNode));
    bt->data=NULL;
}
bool isBiTreeEmpty(BiTree bt){
    if (bt==NULL) return true;// && bt->left==NULL && bt->right==NULL
    else return false;
}
//bool