//判断T1和T2两棵树是否相似。相似是说形状相同

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

bool IsSimilar(BiTree T1, BiTree T2) {
    if (T1 == NULL && T2 == NULL) return true;
    // if (T1->lchild == NULL && T1->rchild == NULL && T2->lchild == NULL && T2->rchild == NULL) return true;
    else if (T1 == NULL || T2 == NULL) return false;

    return IsSimilar(T1->lchild, T2->lchild) && IsSimilar(T1->rchild, T2->rchild);
}