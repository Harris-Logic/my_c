//
// Created by Liang on 2022/7/29.
//

#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 10

typedef int keytype;
typedef int position;
typedef struct BiTNode{
    keytype data;//不能申请数组空间！否则runtime error
    struct BiTNode *left,*right;
}BiTNode,*pBiTNode;
void inTree(pBiTNode &t,keytype key/*,position &pos*/){
    if(t==NULL){
        t=(pBiTNode) calloc(1,sizeof (BiTNode));
        t->data=key;//树空，第一个数组成员 入树
//        pos=0;//pos数组下标初始化
    } else{
        if(key==t->data)
            return;
        else if(key<t->data)
            inTree(t->left,key);
        else if(key>t->data)
            inTree(t->right,key);
    }
}
void inOrder(pBiTNode &t,keytype str[],position &pos){//pos是要辅助 往str[]里写结果用的
    if(t!=NULL){
        inOrder(t->left,str,pos);
        str[pos]=t->data;
        printf("%3d",t->data);
        pos++;
        inOrder(t->right,str,pos);
    }
}

int main(){
    keytype str[MAXSIZE]={0};
    pBiTNode t=NULL;
    for(int k=0;k<MAXSIZE;k++){//87  7 60 80 59 34 86 99 21  3
        int tmp;
        scanf("%d",&tmp);
        inTree(t,tmp);
    }
    int pos=0;
    inOrder(t,str,pos);
    printf("\n");
    int i;
    for(i=0;i<MAXSIZE;i++) {
        if (str[i] == 21) break;
    }
    printf("%d",i);
    return 0;
}
/*input:
87  7 60 80 59 34 86 99 21  3
 output:
  3  7 21 34 59 60 80 86 87 99
2
*/