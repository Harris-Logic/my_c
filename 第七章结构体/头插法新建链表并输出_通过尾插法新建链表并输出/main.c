#include <stdio.h>
#include <stdlib.h>

struct LinkList{
    int data;
    struct LinkList *next;
};

void PrintList(struct LinkList *L){
    L=L->next;
    while(L!=NULL){
        printf("%d",L->data);//打印当前结点数据
        L=L->next;//指向下一个结点
        if(L!=NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
//    struct LinkList *l;
    int zhengshu=0;
    struct LinkList *i=(struct LinkList*)malloc(sizeof(struct LinkList)),*q=(struct LinkList*)malloc(sizeof(struct LinkList));

    i->next=(struct LinkList*)malloc(sizeof(struct LinkList));q->next=(struct LinkList*)malloc(sizeof(struct LinkList));
    struct LinkList *ip=i;

//    while(zhengshu!=9999){
//        scanf("%d",&zhengshu);
//        l->data=zhengshu;
//        struct LinkList *p=(struct LinkList*)malloc(sizeof(struct LinkList));
//        p->next=l->next;
//        l->next=p;
//        l++;
//    }
    while(zhengshu!=9999){
        scanf("%d",&zhengshu);//1 2 3 4 5 9999
        if(zhengshu==9999) break;
        else {
            ip->next->data=zhengshu;
            ip=ip->next;
            ip->next=(struct LinkList*)malloc(sizeof(struct LinkList));

        }
    }
    zhengshu=0;
    while(zhengshu!=9999){
        scanf("%d",&zhengshu);//1 2 3 4 5 9999
        if(zhengshu==9999) break;
        else {
            q->next->data=zhengshu;
            struct LinkList *qp=(struct LinkList*)malloc(sizeof(struct LinkList));
            qp->next=q->next;
            q->next=qp;
        }
    }
    ip->next=NULL;
    PrintList(q->next);
    PrintList(i);
    //    printf("Hello, World!\n");
    return 0;
}
//Description
//        输入3 4 5 6 7 9999一串整数，9999代表结束，通过头插法新建链表，并输出，通过尾插法新建链表并输出。
//
//注意输出要采用如下代码（因为OJ判题对空格敏感，因此需要用下面的打印代码来做）：
//
////打印链表中每个结点的值
//
//void PrintList(LinkList L)
//
//{
//
//    L=L->next;
//
//    while(L!=NULL)
//
//    {
//
//        printf("%d",L->data);//打印当前结点数据
//
//        L=L->next;//指向下一个结点
//
//        if(L!=NULL)
//
//        {
//
//            printf(" ");
//
//        }
//
//    }
//
//    printf("\n");
//
//}//////
//完成作业的同学，可以到微信读书搜索《跟龙哥学C语言编程》，有很多课后习题可以练习，附带答案，或者直接B站搜王道论坛，看王道的数据结构，组成原理。
////
//Input
//3 4 5 6 7 9999，第二行也是3 4 5 6 7 9999，数据需要输入两次
////
//Output
//如果输入是3 4 5 6 7 9999，那么输出是7 6 5 4 3，数之间空格隔开，尾插法的输出是3 4 5 6 7
////
//Sample Input 1
//3 4 5 6 7 9999
//3 4 5 6 7 9999
//Sample Output 1
//7 6 5 4 3
//3 4 5 6 7
//Sample Input 2
//1 3 5 7 9 9999
//1 3 5 7 9 9999
//Sample Output 2
//9 7 5 3 1
//1 3 5 7 9