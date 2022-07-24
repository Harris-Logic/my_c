#include <stdio.h>
struct stu{
    int stu_num;
    char stu_name[30];
    char stu_xb[2];

};
int main() {
    struct stu student1;

    scanf("%d %s %s",&student1.stu_num,&student1.stu_name,&student1.stu_xb);
//    printf("Hello, World!\n");
    printf("%d %s %s",student1.stu_num,student1.stu_name,student1.stu_xb);
    return 0;
}
//101 xiongda m
//
//Description
//        输入一个学生的学号，姓名，性别，用结构体存储，通过scanf读取后，然后再通过printf打印输出
//
//
//        Input
//学号，姓名，性别，例如输入 101 xiongda m
//
//
//Output
//        输出和输入的内容一致，如果输入的是101 xiongda m，那么输出也是101 xiongda m