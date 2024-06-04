//后序遍历的非递归算法。该算法因为没有指向双亲节点的链表，所以不能够回到双亲节点，所以必须借助栈来记忆双亲节点的位置。
//注意，本代码因为有标准答案作参考，故直接采用抽象函数行文，有报错但是代码思想是正确的。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

// void PostOrder(BiTree T) {
//     InitStack(S);
//     BiTNode* p = T, * r;
//     while (p || !IsEmpty(S)) {
//         if (p) {
//             Push(S, p);
//             p = p->lchild;
//         }
//         else {
//             GetTop(S, p);
//             if (p->rchild && p->rchild != r) {
//                 p = p->rchild;
//             }
//             else {
//                 Pop(S, p);
//                 visit(p);
//                 r = p;
//                 p = NULL;//触发回溯
//             }
//         }
//     }
// }

void PostOrder(BiTree T) {
    InitStack(S);
    BiTNode* p = T, * r;

    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            GetTop(S, p);
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            }
            else {
                Pop(S, p);
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }
}


//层序遍历
void LevelTraverse(BiTree T) {
    InitQueue(Q);
    EnQueue(Q, T);
    BiTNode* p;

    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);

        if (p->lchild) EnQueue(Q, p->lchild);
        if (p->rchild) EnQueue(Q, p->rchild);
    }
}