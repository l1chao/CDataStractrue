//层序遍历（倒序版，即自下而上，从右往左）
//这里的思路主要是在原来利用队列的基础上面加上一个栈的利用。实际上为了空间复杂度能够被进一步优化，可以利用一个线性表和双指针实现栈和队列的结合作用。但是这里应该是出于复习的考虑，还是利用一个栈和一个队列来解决问题。

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;


void InvertLevel(BiTree T) {
    InitStack(S);
    InitQueue(Q);
    BiTNode* p = T;

    Enqueue(Q, p);
    Push(S, p);

    while (!IsEmpty(Q)) {
        Dequeue(Q, p);//出栈即访问。一般是出栈到temp，temp再来执行访问操作。
        Push(p); //visit(p);//统一在这里进行层序遍历的节点访问。

        if (p->lchild) Enqueue(Q, p->lchild);
        if (p->rchild) Enqueue(Q, p->rchild);
    }

    while (!IsEmpty(S)) {
        Pop(S, p);
        printf("%d", p->data);
    }
}