//二叉树层序遍历 & 广搜
//核心思想：遍历上一层的同时，添加了下一层，所以全部都是通过“层”的方式来遍历的。

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct  BiNode {
    int data;
    struct BiTree* lchild;
    struct BiTree* rchild;
}BiNode, * BiTree;

void levelorder(BiTree* T) {
    InitQueue(Q);
    BiTree p;

    EnQueue(Q, T);

    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        if (!p->lchild) EnQueue(p->lchild);
        if (!p->rchild) EnQueue(p->rchild);
    }
}

//层序遍历的自下而上 从右到左访问
void reLevelTraverse(BiTree T) {
    InitStack(S);
    InitQueue(Q);

    BiTree p = T;
    EnQueue(Q, p);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        Push(S, p);
        if (p->lchild) EnQueue(Q, p->lchild);
        if (p->rchild) EnQueue(Q, p->rchild);
    }

    while (!IsEmpty(S)) {
        Pop(S, p);
        visit(p);
    }
}


//求树高非递归
void GetTreeH(BiTree T) {
    InitQueue(Q);
    BiTree p = T;
    BiTree r, last = T;
    EnQueue(p);
    int Height;
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        if (p->lchild) {
            EnQueue(Q, p->lchild);
            r = p->lchild;//核心：上一排最后一个节点，被出队+访问后，层序遍历刚好添加完下一层的末尾节点。
        }
        if (p->rchild) {
            EnQueue(Q, p->rchild);
            r = p->rchild;
        }
        if (p == last) {
            Height++;
            last = r;
        }
    }
}


//求树高递归算法
int shugaodigui(BiTree T) {
    if (!T) return 0;
    return max(shugaodigui(T->lchild), shugaodigui(T->rchild)) + 1;
}

int max(int a, int b) {
    if (a >= b) return a;
    return b;
}

int main() {


    return 0;
}