#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//将h2直接插入h1中。h1和h2均为循环单链表。
void Connect(LinkList h1, LinkList h2) {
    LNode* h2_front = h2, * h2_back = h2->next;

    h2_front->next = h1->next;
    h1->next = h2_back;
}

void Connect(LinkList h1, LinkList h2) {
    LNode* h2_next = h2->next;
    h2->next = h1->next;
    h1->next = h2_next;
}

void SimpleConnect(LinkList a, LinkList b) {
    LNode* b_next = b->next;
    b->next = a->next;
    a->next = b_next;
}

int main() {
    return 0;
}