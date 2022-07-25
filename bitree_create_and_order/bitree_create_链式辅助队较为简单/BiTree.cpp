//
// Created by Liang on 2022/7/25.
//

#include "main.h"
//typedef struct BiTree{
//    ElemType data;
//    struct BiTree *left,*right;
//}BiTree,*pBiTree;
void iniBiTree(pBiTree &t){
    t=(pBiTree) calloc(1,sizeof(BiTree));
}
bool isBiTreeEmpty(pBiTree t){
    if(t->data==NULL||t==NULL) return true;//is Empty
    else return false;
}
