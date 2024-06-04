//二叉排序树
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BSTNode {
    int key;
    struct BSTNode* lchild, * rchild;
}BSTNode, * BSTree;

BSTNode* BST_Search(BSTree T, int key) {
    while (T != NULL && key != T->key) {//非递归调用
        if (key < T->key) T = T->lchild;
        else T = T->rchild;
    }

    return T;
}

//因为树是递归结构，所以用递归的方法来寻找点也是可行的。
// 但是这里的递归算法空间复杂度很高O(h)，比上面的O(1)坏了很多。这里作为比较而书写于此。
BSTNode* BST_Search_digui(BSTree T, int key) {
    if (T == NULL) {
        return NULL;
    }
    else if (T->key == key) {
        return T;
    }
    else if (key < T->key) {
        return BST_Search_digui(T->lchild, key);
    }
    else {
        return BST_Search_digui(T->rchild, key);
    }
}

//向二叉排序树里面插入一个点。还是递归地实现。
int BST_Insert(BSTree T, int k) {
    if (T == NULL) {
        BSTNode* n = (BSTNode*)malloc(sizeof(BSTNode));
        n->key = k;
        n->lchild = n->rchild = NULL;
        return 1;
    }
    else if (T->key == k) {
        return 0;
    }
    else if (k < T->key) {
        return BST_Insert(T->lchild, k);
    }
    else {
        return BST_Insert(T->rchild, k);
    }
}

//按照str[]中关键字序列建立二叉排序树
void Create_BST(BSTree T, int str[], int n) {
    T = NULL;
    for (int i = 0; i < n; i++) {
        BST_Insert(T, str[i]);
    }
}
int main() {


    return 0;
}