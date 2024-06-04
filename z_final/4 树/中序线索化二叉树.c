#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ThreadNode {
    int data;
    struct ThreadNode* lchild, * rchild;
    int ltag, rtag;
}ThreadNode, * ThreadTree;

void InThread(ThreadTree p, ThreadTree pre) {
    if (!p) {
        InThread(p->lchild, pre);

        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }

        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }

        pre = p;

        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree T) {

}

int main() {


    return 0;
}