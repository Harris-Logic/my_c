//
// Created by Liang on 2022/7/30.
//

#include "stdio.h"

typedef int listlength;
typedef int keytype;
typedef struct numstractive{
    keytype *data;//这样，回避 在结构体中声明 大量数组空间，挤占main栈空间造成runtime error
    listlength length;//动态数组成员数
}numstractive,*pnumstractive;

int main(){

    return 0;
}