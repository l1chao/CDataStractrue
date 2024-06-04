//循环双链表
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct DNode {
    int data;
    struct DNode* prior, * next;
}DNode, * DLinkList;

bool InitDLinkList(DLinkList L) {
    L = (DNode*)malloc(sizeof(DNode));
    if (L == NULL) {
        return false;
    }

    L->prior = L;
    L->next = L;
    return true;
}

bool IsEmpty(DLinkList L) {
    return L->next == L;
}

bool IsTail(DLinkList L, DNode* p) {
    return p->next == L;
}

//在p节点后面插入s节点
//注意，循环链表的插入，即使是在最后一个位置插入，也不用特殊处理，下面就是正确的插入代码。
bool InsertNextDNode(DNode* p, DNode* s) {
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;//无需像非循环双链表那样考虑最后一个是不是null。
    p->next = s;
    return true;
}

bool DeleteNextDNode(DNode* p, DNode* q) {
    q->next->prior = p;
    p->next = q->next;
    free(q);
    return true;//暂时没有写false对应神什么情况，这里主要是简单了解怎么去删除。
}


int main() {


    return 0;
}