#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//前序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
//后序遍历
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

//求树的深度。主要思想是利用树的递归特性，一棵树的深度等于最大子树深度+1。
int treeDepth(BiTree T) {
    if (T == NULL) {
        return 0;
    }

    int leftLen = treeDepth(T->lchild);
    int rightLen = treeDepth(T->rchild);
    return leftLen > rightLen ? leftLen + 1 : rightLen + 1;

}

//二叉树的层序遍历
// void LevelOrder(BiTree T) {
//     LinkQueue Q; //使用链队列
//     InitQueue(Q);
//     BiTree p;
//     Enqueue(Q, T);
//     while (!IsEmpty(Q)) {
//         DeQueue(Q, p);
//         visit(p);
//         if (p->lchild != NULL) {
//             EnQueue(Q, p->lchild);
//         }
//         if (p->rchild != NULL) {
//             EnQueue(Q, p->rchild);
//         }
//     }
// }
int main() {


    return 0;
}