//
// Created by Liang on 2022/7/30.
//

#include "stdio.h"
#include "string.h"

typedef int listlength;
typedef int keytype,*pkeytype;
typedef struct numstractive{
    keytype *data;//这样，回避 在结构体中声明 大量数组空间，挤占main栈空间造成runtime error
    listlength length;//动态数组成员数
}numstractive,*pnumstractive;

int main(){
    keytype A[]={1,2,4,5,1,5432,85,623,6,26,3462,439,26,62,62,637,7465,8};
    pkeytype b;
    memcpy(b,A,sizeof (A));//string.h 按sizeof(A)的大小，一对一copy至b指向的空间


    return 0;
}