#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;


//中序遍历非递归
void InOrder_Nodigui(BiTree T) {
    InitStack(S);
    BiTree p = T;

    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }

        else {
            Pop(S, p); //出栈+回退指针
            visit(p);
            p = p->rchild;
        }
    }
}


//前序遍历非递归
void PreOrder_Nodigui(BiTree T) {
    InitStack(S);
    BiTree p = T;

    while (p || !IsEmpty(S)) {
        if (p) {
            visit(p);
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);
            p = p->rchild;
        }
    }
}


//后序遍历非递归
void PostOrder_Nodigui(BiTree T) {
    InitStack(S);
    BiTree p = T;
    BiTree r;

    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            GetTop(S, p);//先回退，再右转
            if (p->rchild != NULL && p->rchild != r) {
                p = p->rchild;
            }

            else {
                visit(p);
                Pop(S, p);
                r = p;//为了访问右子树
                p = NULL;//为了访问右子树
            }
        }
    }
}


//中序遍历非递归 求树高——不好求，因为添一层的操作并不明确
// void InOrder_Nodigui(BiTree T) {
//     InitStack(S);
//     BiTree p = T;

//     int Height = 0;
//     while (p || !IsEmpty(S)) {
//         if (p) {
//             Push(S, p);
//             p = p->lchild;
//             Height++;
//         }

//         else {
//             Pop(S, p); //出栈+回退指针
//             p = p->rchild;
//             Height--;
//         }
//     }
// }

int main() {

    return 0;
}