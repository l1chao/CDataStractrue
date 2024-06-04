//双链表操作及测试

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>n 

typedef struct DNode {
    int val;
    struct DNode* next;
    struct DNode* prior;

}DNode, * DoubleList;

//双链表构建
