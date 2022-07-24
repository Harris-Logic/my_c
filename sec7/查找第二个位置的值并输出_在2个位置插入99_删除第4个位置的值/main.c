#include <stdio.h>
#include "stdlib.h"

struct LinkList{
    int data;
    struct LinkList *next;
};
void PrintList(struct LinkList *L){
    L = L->next;
    while (L != NULL){
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}

int main() {
    int shuru=0;
    struct LinkList *weicha=(struct LinkList*)malloc(sizeof(struct LinkList));
    struct LinkList *tmp=(struct LinkList*)malloc(sizeof(struct LinkList));
    tmp=weicha;
    weicha->next=(struct LinkList*)malloc(sizeof(struct LinkList));

    while(shuru!=9999){
        scanf("%d",&shuru);//3 4 5 6 7 9999
        if(shuru==9999) break;
        else{//尾插操作
            tmp->next=(struct LinkList*)malloc(sizeof(struct LinkList));
            tmp->next->data=shuru;//tmp->next=weicha->next;weicha->next=tmp;

            tmp=tmp->next;
        }
    }//输入循环结束，链表顺序建立
    tmp=weicha;//初始化

    for(int i=0;i!=(2-1);i++) tmp=tmp->next;//此时tmp->next是第二位//插入99到2位
    printf("%d\n",tmp->next->data);

    struct LinkList *charu=(struct LinkList*)malloc(sizeof(struct LinkList));
    charu->data=99;
    charu->next=tmp->next;
    tmp->next=charu;//至此插入99到2号位完成

//    printf("",);
    PrintList(weicha);

    tmp=weicha;
    for(int i=0;i<(4-1);i++)//删除现第四个位置
        tmp=tmp->next;
    struct LinkList *shanchudisi;//此时tmp->next是要删掉的元素
    shanchudisi=tmp->next;
    tmp->next=tmp->next->next;
    free(shanchudisi);

    PrintList(weicha);
    return 0;
}
//Description
//        输入3 4 5 6 7 9999一串整数，9999代表结束，通过尾插法新建链表，查找第二个位置的值并输出，在2个位置插入99，输出为  3 99  4  5  6  7，删除第4个位置的值，打印输出为  3 99  4  5  6  7。
//
//输出函数如下：
//
//void PrintList(LinkList L)
//
//{
//
//    L = L->next;
//
//    while (L != NULL)
//
//    {
//
//        printf("%3d", L->data);//打印当前结点数据
//
//        L = L->next;//指向下一个结点
//
//    }
//
//    printf("\n");//
//}//
//针对双向链表，有时间的同学自己练习即可，这道题同样也可以用双向链表来实现一遍
////
//        Input
//输入是3 4 5 6 7 9999
//
//
//Output
//        输出是
//
//4
//
//3 99  4  5  6  7
//
//3 99  4  6  7
//
//
//Sample Input 1
//3 4 5 6 7 9999
//Sample Output 1
//4
//3 99  4  5  6  7
//3 99  4  6  7
//Sample Input 2
//1 3 5 7 9 9999
//Sample Output 2
//3
//1 99  3  5  7  9
//1 99  3  7  9