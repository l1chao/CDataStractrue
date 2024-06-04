//将叶节点连接为单链表，返回这个单链表。

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

BiTNode* func(BiTree T) {
    InitStack(S);
    BiTNode* p = T, * r, * head;
    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);
            if (p->rchild) {
                p = p->rchild;
            }
            else {
                if (head == NULL) head = p;
                if (r != NULL) r->rchild = p;
                r = p;
                p = NULL;
            }
            // if (p->rchild) {
            //     p = p->rchild;
            // }
            // else {
            //     if (head == NULL) { head = p; }
            //     if (r != NULL) r->rchild = p;
            //     r = p;
            //     p = NULL;
            // }
        }
    }
    r->rchild = NULL;

    return head;
}