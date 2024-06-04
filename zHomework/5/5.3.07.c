//判断是否是完全二叉树

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

bool IsCompleteTree(BiTree T) {
    InitQueue(Q);//Q是一个BiTNode指针数组
    EnQueue(Q, T);
    BiTNode* p;

    while (!IsEmpty(Q)) {
        DeQueue(Q, p);

        if (p == NULL) {//第一个NULL后，该if接管后续程序
            while (!IsEmpty(Q)) {
                DeQueue(Q, p);
                if (p != NULL) return false;
            }
            return true;
        }

        EnQueue(Q, p->lchild);
        EnQueue(Q, p->rchild);
    }

    return true;//最近老是会写一些不会被执行到的返回值。这种习惯是不是不好的？ 
}

bool IsCompleteTree(BiTree T) {
    InitQueue(Q);
    EnQueue(Q, T);
    BiTNode* p;
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);

        if (p) {
            EnQueue(Q, p->lchild);
            EnQueue(Q, p->rchild);
        }
        else {
            while (!IsEmpty(Q)) {//大循环结束。
                DeQueue(Q, p);
                if (p != NULL) return false;
            }
        }
    }

    //应该利用大循环结束条件退出循环。
    return true;
}

//对，应该这么理解：如果一旦循环中间出现了接管后续程序的结束状态/判定情况，一定包含了大循环的结束条件，所以接管情况一定是可以通过大循环结束情况来实现的。简单来说，接管情况应该规范成大循环的结束情况，结束应该通过大循环来结束，应该是（规范性）而且能够是（可能性）。