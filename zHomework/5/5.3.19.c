//求树的带权路径长度。注意，一棵树的带权路径长度==所有叶节点的带权路径长度之和

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

float GetWPL(BiTree T) {
    float sum = 0;
    InitStack(S);
    int a[256];
    int  b[10] = a[2:3];
    BiTNode* p = T, * r;
    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            GetTop(S, p);
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            }
            else {
                Pop(S, p);
                if (!p->lchild && !p->rchild) {
                    sum += GetLength(S) * p->data;
                }

                r = p;
                p = NULL;
            }
        }
    }
}