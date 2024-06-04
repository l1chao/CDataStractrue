#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;

int BST_Insert(BiTree T, int k) {
    if (T == NULL) {//T本身就是一个桥梁的指针，是叶节点的孩子指针
        T = (BiTree)malloc(sizeof(BSTNode));
        T->lchild = NULL;
        T->rchild = NULL;
        T->data = k;
        return 1;//插入成功
    }

    else if (T->data == k) {
        return 0;//号码重复，插入失败
    }
    else if (k < T->data) return BST_Insert(T->lchild, k);
    else return BST_Insert(T->lchild, k);
}