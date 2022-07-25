//
// Created by Liang on 2022/7/25.
//

#include "main.h"

//typedef struct BiTree{
//    Elemtype data;//结点里是char、int型之类的东西
//    struct BiTree* left;
//    struct BiTree* right;
//}BiTree,*pBiTree;
void iniBiTree(pBiTree &bt){
    bt=(pBiTree) calloc(1,sizeof (BiTree));
}
//这个思路 目前应该没问题//数的判空需要两层判断，第一层后跟着第二层。这样既可iniBiTree
bool isBiTreeEmpty(pBiTree bt){
    if(bt==NULL) return true;//is Empty
    if(bt->data==NULL) return true;

    return false;
}
