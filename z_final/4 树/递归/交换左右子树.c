#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct  BiNode {
    int data;
    struct BiTree* lchild;
    struct BiTree* rchild;
}BiNode, * BiTree;


//交换左右子树
//递归怎么用呢？
void swap(BiTree T) {
    if (T) {
        swap(T->lchild);
        swap(T->rchild);
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}
int main() {


    return 0;
}