// #define _CRT_SECURE_NO_
#include<stdio.h>

int main(){
  int a;
  char c;
  // char s[];
  char s[]="";

  scanf("%d",&a);
  printf("a=%d\n",a);
  scanf("%s",s);//%d %f %s类型，scanf会卡住。
  printf("s=%s",s);
  // scanf("%c",&c);//缓冲区为空的时候，scanf才会卡住。但是这个时候缓冲区不为空。缓冲区内="\n"。所以直接打印c=
  // printf("c=%c",c);
  
  return 0;
}
// //已放弃，手动gcc编译调试运行吧。
// # liang @ LianMBP in ~/Desktop/c [18:30:42] 
// $ gcc main.c -o main     