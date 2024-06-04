#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//删除带头结点链表内所有值为x的节点并释放。
void Delete_x(LinkList L, ElemType x) {
    if (L == NULL) {
        return;
    }

    LNode* p = L;
    for (;p->next != NULL;) {
        if (p->next->val == x) {
            p->next = p->next->next;
        }
        else {
            p = p->next;
        }
    }
    return;
}

int main() {
    return 0;
}