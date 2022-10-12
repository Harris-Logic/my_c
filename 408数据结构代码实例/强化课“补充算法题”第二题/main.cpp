//
// Created by Liang on 2022/10/12.
//

// 注：这段代码对应强化课“补充算法题”第二题
// 这段代码实现了关键字0~999范围的"基数排序"
//咸鱼注：大家可以在自己电脑上新建一个 C++ 项目，并把这段代码复制到 main 函数前边，然后在你的 main 函数里调用 test_RadixSort() 这个函数。跑一跑看看效果
//提示：用电脑网页版看，体验更好一些
//注：这段代码对应强化课“补充算法题”第二题
// 个人微博：@王道咸鱼学长-计算机考研

#ifndef CODE_RADIXSORT_H
#define CODE_RADIXSORT_H

#include "random"
#include "stdio.h"

//用于存储关键字的结点
typedef struct RaNode {
    int key;
    struct RaNode * next;
} Node;

//队列结点定义
typedef struct {
    RaNode * front;    //队头指针
    RaNode * rear;     //队尾指针
} Queue;

//取出关键字 key 的第 d 位（第1位是个位，第2位是十位，第3位是百位
int getRadix(int key, int d){
    if(d==1) return key % 10;
    if(d==2) return (key/10) % 10;
    if(d==3) return (key/100) % 10;
    return -1;  //参数d有误
}

//第 k 趟分配
void distribute (RaNode * head, int k, Queue list[]) {
    //每次摘下链头元素进行分配
    while (head->next!=NULL){
        RaNode * p = head->next;          //p指向链头元素
        head->next = p->next;           //摘下链头元素
        p->next=NULL;

        int r = getRadix(p->key, k);    //取出当前结点第k位
        //目前第r个分配队列为空
        if (list[r].front == NULL){
            list[r].front = p;          //将结点p插入第r个队列
            list[r].rear = p;
        } else {
            list[r].rear->next = p;     //将结点p插入第r个队列的队尾
            list[r].rear = p;           //修改队尾指针
        }
    }
}

//第 k 趟回收
void collect(RaNode * head, int k, Queue list[]) {
    //依次将 9~0 队列中的元素整体摘下，用头插法插入单链表 head
    for (int i=9; i>=0; i--) {
        if (list[i].front == NULL) continue;    //空队列直接跳过
        list[i].rear->next = head->next;        //将第i个分配队列整体头插到链表中
        head->next = list[i].front;
        list[i].front = NULL;
        list[i].rear = NULL;
    }
}

//对单链表 head 进行基数排序，其中指针 head 指向头结点
int RadixSort(RaNode * head) {
    Queue list[10];  //用于实现基数排序的10个队列
    for (int i=0; i<10; i++){
        list[i].front = NULL;
        list[i].rear = NULL;
    }
    //由于关键字取值范围为 0~999，因此仅需 3 趟分配/回收
    for (int r=1; r<=3; r++){
        distribute(head, r, list);
        collect(head, r, list);
    }
}

//打印单链表的值
void printList (RaNode * head) {
    RaNode * p = head;
    printf("【链表的值】：");
    while (p->next!=NULL) {
        printf("%d ", p->next->key);
        p = p->next;
    }
    printf("\n");
}


//【测试代码】：实现对单链表的基数排序，关键字范围是 0~999
//先随便建立一个乱序的带头结点单链表，再对单链表进行基数排序
int test_RadixSort() {
    //新建一个带头结点的乱序单链表
    RaNode * head = (RaNode *) malloc (sizeof(RaNode));
    head->next = NULL;
    //随机插入一些数据到 单链表 head 中
    for (int i=0; i<100; i++){
        RaNode * p = (RaNode *) malloc (sizeof(RaNode));
        p->key = rand() % 1000;     //此处rand函数生成随机整数，对1000取余数，关键字范围控制在0~999以内
        p->next = head->next;
        head->next = p;
    }

    printList(head);
    RadixSort(head);
    printList(head);
}

#endif //CODE_RADIXSORT_H