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

    L->prior = NULL;
    L->next = NULL;
    return true;
}

//带头结点。此时头结点前面不会有其他节点。
bool IsEmpty(DLinkList L) {
    if (L->next == NULL) {
        return true;
    }

    return false;
}

//双链表，将s节点插入p节点后面
bool InsertNextDNode(DNode* p, DNode* s) {
    if (p == NULL || s == NULL) {
        return false;
    }

    s->next = p->next;
    s->prior = p;

    if (p->next != NULL) {
        p->next->prior = s;
    }

    p->next = s;//上游最后删。前面三个位置可任意置换。

    return true;
}

//删除p的后继节点
bool DeleteNextDNode(DNode* p) {
    //删除只需要修改两条连接即可，因为剩下的两条是被删除节点的两条。
    if (p == NULL) {
        return false;
    }

    DNode* q = p->next;
    if (q->next != NULL) {
        q->next->prior = p;
    }
    p->next = q->next;
    free(q);

    return true;
}

//销毁一个双链表
void DestroyList(DLinkList L) {
    while (L->next != NULL) {
        DeleteNextDNode(L);
    }
    free(L);
    L = NULL;
}


int main() {


    return 0;
}