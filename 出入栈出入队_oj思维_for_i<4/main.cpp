#include "stdio.h"
//#include <stdio.h>
#define MaxSize 5

typedef struct {//栈
    int data[MaxSize];
    int top;
}Stack;
bool initstack(Stack &s){//初始化
    s.top=-1;
    return true;
}
bool stackempty(Stack s){//判空
    if(s.top==-1) return true;
    return false;
}
bool push(Stack &s,int x){
    if(s.top==MaxSize-1) return false;//栈满，push压栈失败
    s.data[++s.top]=x;
    return true;
}//入栈
bool pop(Stack &s,int &x){
    if(stackempty(s)) return false;//栈空，出栈失败
    x=s.data[s.top--];
    return true;
}//出栈

typedef struct {//队
    int data[MaxSize];
    int front,rear;
}Queue;
bool initqueue(Queue &q){//队列初始化有点问题。front和rear数值设定？init后是空队。出队会失败
    q.rear=0;
    q.front=0;
    return true;
}

bool EnQueue(Queue &Q,int x){//尾进头出
    if((Q.rear+1)%MaxSize==Q.front) return false;//判满
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}
bool DeQueue(Queue &Q,int &x){
    if(Q.rear==Q.front) return false;//队空，出对失败
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}
int main() {
    Stack s;
    Queue q;
    initstack(s);
    initqueue(q);
    for(int i=0;i<3;i++) {//入栈
        int x;
        scanf("%d", &x);//3 4 5
        push(s, x);
    }

    while (s.top>=0){//出栈打印
        int x;//=s.data[s.top--];
        pop(s,x);
        printf("%2d",x);
    }
    printf("\n");
    for(int i=0;i<5;i++){//入队
        int x;
        scanf("%d",&x);////3 4 5 6 7
        bool flag=EnQueue(q,x);
        if(!flag) printf("false\n");
    }
    for(int i=0;i<4;i++){//出队，并打印
        int x;
        DeQueue(q,x);
        printf("%2d",x);
    }

    return 0;
}

//Description
//        新建一个栈，读取标准输入 3个整数3 4 5，入栈3 4 5，依次出栈，打印 5 4 3，新建循环队列（Maxsize为5），读取标准输入3 4 5 6 7，入队7时，队满，打印false，然后依次出队，输出 3 4 5 6
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