//
// Created by Liang on 2022/7/23.
//

#include "function.h"

void initStack(pStack &s){
    s=(pStack) calloc(1,sizeof (Stack));
    s->top=-1;
}
bool isStackEmpty(pStack s){
    if(s->top==-1) return true;
    else return false;
}
bool push(pStack &s,ElemType x){
    if(s->top==(MAXSIZE-1)) return false;//入栈失败
    else {
        s->top++;
        s->data[s->top]=x;
        return true;
    }
}
bool pop(pStack &s,ElemType &x){
    if(isStackEmpty(s)) return false;//空栈，出栈失败
    else{
        x=s->data[s->top];
        s->data[s->top]=NULL;
        s->top--;
    }
}
