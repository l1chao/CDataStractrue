//非递归算法计算二叉树高度。
//思路：之前想用后序遍历看栈的最大高度。参考答案里面是直接用层序遍历。这提醒了层序遍历本身不是递归算法。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 1024

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

int TreeDepth(BiTree T) {
    BiTNode* Q[MaxSize];
    int front = -1, rear = -1;//front虚，rear实
    Q[++rear] = T;

    int last = 0, level = 0;

    BiTNode* p;
    while (front < rear) {//front走到一层末尾就Level+1，最后一层统一了。
        p = Q[++front];
        if (p->lchild) Q[++rear] = p->lchild;
        if (p->rchild) Q[++rear] = p->rchild;

        if (front == last) {
            last = rear;
            level++;
        }
    }
    return level;
}