#include <stdio.h>
#include "stdlib.h"
void shuru(char **p){//传入是二级指针
    //malloc用法：include "stdlib.h"，以及(char*)malloc(40*sizeof(char))
    *p=(char*)malloc(30*sizeof(char));//二级指针p进行了一级引用(下降一级)

    fgets(*p,100,stdin);//输入也是要 对一级引用*p进行fgets输入char字符串
}
int main() {
    char *p;
    shuru(&p);//c这里传入的是指针p的地址，而不是指针p本体
    puts(p);
//    printf("Hello, World!\n");
    return 0;
}

//下面是实现同样过程的c++版本。确实代码表述要简洁点
//#include <iostream>
//#include "cstdlib"
//
//void shuru(char *&p){
//p= (char*) malloc(20*sizeof(char));//malloc用法：include "cstdlib"，以及(char*)malloc(40*sizeof(char))
//fgets(p,100,stdin);
//}
//int main() {
//    char *p;
//    shuru(p);
//    puts(p);
////    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

//Description
//        使用C++的引用，注意提交时把代码选为C++；在主函数定义字符指针 char *p,然后在子函数内malloc申请空间，通过fgets读取字符串，然后在主函数中进行输出；要求子函数使用C++的引用，注意在C++中从标准输入读取字符串，需要使用fgets(p,100,stdin)
//
//
//Input
//        输入一个字符串，例如 I love C language
//
//
//        Output
//如果输入的是I love C language，那么输出也是I love C language