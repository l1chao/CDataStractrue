#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, * LinkList;


bool InitList(LinkList L) {
    L = (LNode*)malloc(sizeof(LNode));

    if (L == NULL) {
        return false;
    }

    L->next = L;
    return true;
}

bool IsEmpty(LinkList L) {
    return L->next == L;
}

bool IsTail(LinkList L, LNode* p) {
    return p->next == L;
}


int main() {


    return 0;
}