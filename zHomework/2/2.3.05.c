#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//有头结点逆置。
//就地逆置我还没想过捏。这种其实是很普遍的。
//注意，我这里没有用尾指针，因为首节点（头结点下一个节点）在起着尾指针的作用。
void LinkReverse(LinkList L) {
    LNode* p = L->next;
    LNode* temp;
    for (;p->next != NULL;) {
        temp = p->next;
        p->next = temp->next;

        temp->next = L->next;
        L->next = temp;
    }
}

//有头结点反转链表
void LinkReverse(LinkList L) {
    if (L == NULL || L->next == NULL)return;

    LNode* p = L->next;
    LNode* temp;
    while (p->next != NULL) {
        temp = p->next;
        p->next = temp->next;
        temp->next = L->next;
        L->next = temp;
    }
}

int main() {
    return 0;
}