//给出前序遍历数组和中序遍历数组，恢复二叉树。相当于机算。
//注意，为了简便，所给数组元素值均不同。

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//返回当前Pre和In序列决定的二叉树的根节点和根节点的左右子树。
BiTNode* FindRoot(int Pre[], int l1, int h1, int In[], int l2, int h2) {
    BiTNode* newnode = (BiTNode*)malloc(sizeof(BiTNode));
    newnode->data = Pre[l1];

    int loc = 0;
    while (In[loc] != Pre[l1]) {
        loc++;
    }
    int llen = loc - l2;
    int rlen = h2 - loc;

    if (llen) {
        newnode->lchild = FindRoot(Pre, l1 + 1, l1 + llen, In, l2, l2 + llen - 1);
    }
    else {
        newnode->lchild = NULL;
    }

    if (rlen) {
        newnode->rchild = FindRoot(Pre, h1 - rlen + 1, h1, In, h2 - rlen + 1, h2);
    }
    else {
        newnode->rchild = NULL;
    }

    return newnode;
}