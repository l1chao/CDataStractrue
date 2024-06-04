//求先序遍历里面第k个节点的值

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

int GetPreKth(BiTree T, int k) {
    InitStack(S);
    BiTNode* p = T;

    int flag = 1;
    int val = 0;
    while (p || !IsEmpty(S)) {
        if (p) {
            if (flag == k) {
                val = p->data;
                break;
            }
            flag++;//这种flag++应该被视作更新步骤，所以为了自己的逻辑自洽，应当尽量放在EndJudge后面。
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);
            p = p->rchild;
        }
    }

    return val;
}