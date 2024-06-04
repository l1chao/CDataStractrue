#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;

BSTNode* BSTSearch(BiTree T, int key) {
    while (T != NULL && key != T->data) {
        if (key < T->data) T = T->lchild;
        else T = T->rchild;
    }
    return T; //查找关键字，找到节点，需要用节点中数据，返回节点。
}

int main() {


    return 0;
}