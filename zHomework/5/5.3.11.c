//删除所有以x为值的节点的子树，并释放相应空间
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

void Answer(BiTree T, int x) {
    T = DeleteX(T, x);
}
BiTNode* DeleteX(BiTree T, int x) {
    if (T == NULL) return NULL;
    if (T->data == x) {
        DestroyTree(T);
        return NULL;
    }

    T->lchild = DeleteX(T->lchild, x);
    T->rchild = DeleteX(T->rchild, x);
    return T;
}

//c语言销毁一棵树
void DestroyTree(BiTree T) {
    if (T == NULL) return;
    DestroyTree(T->lchild);
    DestroyTree(T->rchild);
    free(T);
}