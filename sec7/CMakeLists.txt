cmake_minimum_required(VERSION 3.19)
project(sec7)

set(CMAKE_CXX_STANDARD 14)

add_executable(sec7 main.cpp)

ADD_SUBDIRECTORY(使用C++的引用)
ADD_SUBDIRECTORY(使用C的引用)
ADD_SUBDIRECTORY(头插法新建链表并输出_通过尾插法新建链表并输出)
ADD_SUBDIRECTORY(查找第二个位置的值并输出_在2个位置插入99_删除第4个位置的值)
ADD_SUBDIRECTORY(栈_队列_链式实现_未完成)
ADD_SUBDIRECTORY(第一次输入插入的元素值，第二次输入删除的位置)
ADD_SUBDIRECTORY(结构体初探)
ADD_SUBDIRECTORY(二叉树层次建树)