//求二叉树的宽度

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 1024

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;


int Width(BiTree T) {
    int width = 0;//求宽度。

    BiTNode* Q[MaxSize];
    int front = -1, rear = -1;
    int last = 0;
    BiTNode* p;
    while (!IsEmpty(Q)) {
        p = Q[++front];
        if (p->lchild) EnQueue(Q, p->lchild);
        if (p->rchild) EnQueue(Q, p->rchild);

        if (front == last) {
            width = width > rear - front ? width : rear - front;
            last = rear;
        }
    }

    return width;
}