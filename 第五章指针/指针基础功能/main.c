#include <stdio.h>

int main() {
    int i=3,*i_pointer;
    int a[]={1,2,3,4,2};
//    int *a,*b,*c;
//    i_pointer=&i;//i_pointer里的内容是i的地址值
//    printf("i=%d,i_pointer=%f,*i+pointer=%d",i,i_pointer,*i_pointer);
    for(int j=0;j<5;j++) printf("a[%d]=%d\n",j,*(a+j));//偏移
    return 0;
}
