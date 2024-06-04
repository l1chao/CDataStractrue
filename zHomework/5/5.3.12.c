//打印值为x的节点的所有祖先

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

void PrintAncestor(BiTree T, int x) {
    InitStack(S);
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
                if (p->data == x) {
                    break;
                }
                r = p;
                p = NULL;//右子空弹爷
            }
        }
    }

    while (!IsEmpty(S)) {
        Pop(S, p);
        printf("%d", p->data);
    }
}