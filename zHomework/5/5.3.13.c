//找到两个节点的公共祖先

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 1024

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//你看，只要熟悉栈的操作，都不在话下。所以有空的时候熟悉栈的使用是不亏的。
BiTNode* FindClosestPublicAncestor(BiTree T, BiTNode* x, BiTNode* y) {
    BiTNode* p = T, * r;
    BiTNode* a[MaxSize], * b[MaxSize];
    int pa = 0, pb = 0;

    while (p || pa != 0) {
        if (p) {
            a[pa++] = p;
            p = p->lchild;
        }
        else {
            p = a[pa - 1];
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            }
            else {
                p = a[--pa];
                if (p == x) {
                    break;
                }
            }

        }
    }

    while (p || pb != 0) {
        if (p) {
            a[pb++] = p;
            p = p->lchild;
        }
        else {
            p = a[pb - 1];
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            }
            else {
                p = a[--pb];
                if (p == y) {
                    break;
                }
            }

        }
    }

    pa = pa < pb ? pa : pb;
    pb = pa;

    while (a[pa] != b[pb]) {
        pa--;
        pb--;
    }

    return a[pa];
}