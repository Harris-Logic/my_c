//
// Created by Liang on 2022/10/12.
//

// 注：这段代码对应强化课“补充算法题”第一题
// 这段代码用单链表存储多项式，多项式的各个项按照指数递增的顺序存储在单链表中。另外，Addition 函数实现了两个多项式的加法
//咸鱼注：大家可以在自己电脑上新建一个 C++ 项目，并把这段代码复制到 main 函数前边，然后在你的 main 函数里调用 test_PolynomialAdditation() 这个函数。跑一跑看看效果
//提示：用电脑网页版看，体验更好一些
//注：这段代码对应强化课“补充算法题”第一题

// 个人微博：@王道咸鱼学长-计算机考研

#ifndef CODE_POLYNOMIALADDITATION_H
#define CODE_POLYNOMIALADDITATION_H

#include "stdio.h"
#include "stdlib.h"
//多项式的数据结构定义
typedef struct PoNode {
    int co;   //系数，此处假设系数都为整数
    int ex;   //指数
    struct PoNode *next;    //指向下一个结点
} *Polynomial;

/**
 * 打印多项式p
 * @param p
 */
void printPolynomial (Polynomial p){
    printf("【多项式】：");
    if (p==NULL)
        printf("这是一个空多项式\n");
    while (p!=NULL){
        printf("%dX^%d ", p->co, p->ex);
        p = p->next;
    }
    printf("\n");
}

/**
 * 往多项式 p 中插入新结点，插入后任然保持按指数递增
 * @param p
 * @param co    系数
 * @param ex    指数
 * @return
 */
int InsertNode(Polynomial &p, int co, int ex){
    //malloc一个新结点
    struct PoNode * q = (struct PoNode *)malloc(sizeof(struct PoNode));
    q->ex = ex;
    q->co = co;
    q->next = NULL;

//    //原本是个空链表，查到链头即可
//    if (p == NULL){
//        printf("【插入成功】：%dX^%d ", q->co, q->ex);
//        return 1;               //插入成功，返回1
//    }

    struct PoNode * find = p;         //用指针find遍历链表
    struct PoNode * pre = NULL;       //指向find的前驱结点

    //多项式链表中，各节点的指数依次递增，遍历找到新结点的后继
    while (find!=NULL && find->ex < ex){
        if(find->ex == ex){
            free(q);    //释放空间
            printf("【插入失败】：原本就有相同指数的项\n");
            return 0;
        }
        pre = find;
        find=find->next;
    }

    q->next = find;         //新结点的next指针指向其后继
    if (pre==NULL) {
        p=q;                //新结点插入到链头
    } else {
        pre->next = q;      //新结点插入到pre之后
    }
    printf("【插入成功】：%dX^%d \n", q->co, q->ex);
    return 1;               //插入成功，返回1
}

/**
 * 初始化两个多项式，插入一些测试数据，并打印
 * @param p
 * @param q
 * @return
 */
int InitPolynomial(Polynomial &p, Polynomial &q) {
    //A(x) = 2 + 4x^3^ - x^6^ + 5x^7^ 和 多项式 B(x) = x^3^ + 2x^7^ - 2x^8^
    InsertNode(p, 2, 0);
    InsertNode(p, 4, 3);
    InsertNode(p, -1, 6);
    InsertNode(p, 5, 7);
    printPolynomial(p);

    InsertNode(q, 1, 3);
    InsertNode(q, 2, 7);
    InsertNode(q, -2, 8);
    printPolynomial(q);
}

//a和b两个多项式相加，相加的结果合并到a
int Addition (Polynomial &a, Polynomial &b){
    if (a == NULL || b == NULL)
        return 0;       //两个多项式不能为空

    struct PoNode *p=a, *q=b;      //p、q 两个指针遍历a、b两个单链表
    struct PoNode *pPre=NULL;      //pPre 用于记录 p 的前驱
    while (p!=NULL && q!= NULL) {
        if (p->ex < q->ex) {            //p结点的指数更小
            pPre = p;
            p = p->next;
        } else if (p->ex > q->ex) {     //q结点的指数更小，将q插入到p之前
            if (pPre == NULL){
                //p是单链表a的第一个结点，那么要将q前插到p之前，只能修改头指针a
                a = q;
                q = q->next;
                a->next = p;
                pPre = a;
            } else {
                struct PoNode * s = q;
                q = q->next;
                s->next = p;
                pPre->next = s;     //前插
                pPre = s;
            }
        } else {          //p和q所指结点的指数相同，则统一合并到p
            p->co += q->co;
            pPre = p;
            p = p->next;
            struct PoNode * s = q;
            q = q->next;
            free(s);
        }
    }
    if (p==NULL) {  //p==NULL，说明多项式b中还有一些项没有合并
        pPre->next = q;
    }
}

/*
 * 测试用例代码入口（实现两个多项式的加法）
 */
int test_PolynomialAdditation() {

    //数据结构强化课补充试题第一题，"多项式加法"测试用例
    Polynomial p=NULL,q=NULL;
    InitPolynomial(p, q);
    Addition(p,q);
    printPolynomial(p);
    return 0;
}



#endif //CODE_POLYNOMIALADDITATION_H