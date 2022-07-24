#include <stdio.h>
#include "stdlib.h"

struct my_stack{//栈
    int data;
    struct my_stack* next;
};
void initstack(struct my_stack* s){//栈初始化
    s=(struct my_stack*) malloc(sizeof (struct my_stack));
    s->next=NULL;
}
void instack(struct my_stack* s,int ruzhanshuzi){//入栈
    struct my_stack* ruzhanyuansu=(struct my_stack*) malloc(sizeof (struct my_stack));
    ruzhanyuansu->data=ruzhanshuzi;
    ruzhanyuansu->next=s->next;
    s->next=ruzhanyuansu;
}
void outstack(struct my_stack* s,int *chuzhanfanhuizhi){//出栈
    if(s->next==NULL) return;
    struct my_stack* chuzhanyuansu=(struct my_stack*) malloc(sizeof (struct my_stack));
    chuzhanyuansu=s->next;
    s->next=s->next->next;
    //    s->data=NULL;
    chuzhanfanhuizhi=chuzhanyuansu->data;//指针型形参
    free(chuzhanyuansu);
}

struct my_queue_item{//队列里的元素类型
    int data;
    struct my_queue_item *pre;
    struct my_queue_item *next;
};
struct my_queue{//队列类型结构体

    struct my_queue_item* head;//头进
    struct my_queue_item* rear;//尾出
};

void initqueue(struct my_queue* q){//队初始化
    q=(struct my_queue*) malloc(sizeof (struct my_queue));
    q->head=q->rear=(struct my_queue_item*) malloc(sizeof (struct my_queue_item));
//    q->head->next=q->rear;
//    q->head->pre=q->rear;
//    q->rear->next=q->head;
//    q->rear->pre=q->head;//
    q->head->next=NULL;
    //q->head->pre=NULL;
}
void inqueue(struct my_queue* q,int ruduishuzi){
    struct my_queue_item* ruduiyuansu=(struct my_queue_item*) malloc(sizeof (struct my_queue_item));
    ruduiyuansu->data=ruduishuzi;
    ruduiyuansu->next=q->head->next;
    ruduiyuansu->pre=q->head;
    q->head->next->pre=ruduiyuansu;
    q->head->next=ruduiyuansu;//q->head是个空的节点，仅保存队列名.队的第一个元素是q->head->next

}
void outqueue(struct my_queue* q,int *chuduifanhuizhi,int* chuduishuzi){
    struct my_queue_item* chuduiyuansu=(struct my_queue_item*) malloc(sizeof (struct my_queue_item));
    if(q->head==q->rear) return;
    chuduishuzi=q->rear->data;
    chuduiyuansu=q->rear;
    q->rear=q->rear->pre;

}
int main() {
    printf("Hello, World!\n");
    return 0;
}
//Description
//        新建一个栈，读取标准输入3个整数3 4 5，入栈3 4 5，依次出栈，打印 5 4 3，新建循环队列（Maxsize为5），读取标准输入3 4 5 6 7，入队7时，队满，打印false，然后依次出队，输出 3 4 5 6
//
//
//Input
//        读取标准输入，内容依次是3 4 5，换行后，接着是3 4 5 6 7
//
//
//Output
//        如果输入是3 4 5，换行，接着是3 4 5 6 7，那么输出是
//
//5 4 3
//
//false
//
//3 4 5 6
//
//注意每个数字占用两个字符的位置，5之前是有一个空格的，第三行的3之前也是有一个空格的
//
//
//        Sample Input 1
//3 4 5
//3 4 5 6 7
//Sample Output 1
//5 4 3
//false
//3 4 5 6
//Sample Input 2
//1 3 9
//1 3 5 7 9
//Sample Output 2
//9 3 1
//false
//1 3 5 7