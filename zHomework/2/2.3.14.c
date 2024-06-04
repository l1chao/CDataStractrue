#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//将a、b中公共值形成一个新链表。这个双指针是真的有内容。
LNode* GetPublicNode(LinkList a, LinkList b) {
    LNode* new = (LNode*)malloc(sizeof(LNode));
    new->next = NULL;
    LNode* r = new;

    LNode* pa = a->next, * pb = b->next;
    while (pa != NULL && pb != NULL) {
        if (pa->val < pb->val) {
            pa = pa->next;
        }
        else if (pa->val > pb->val) {
            pb = pb->next;
        }
        else {
            LNode* newNode = (LNode*)malloc(sizeof(LNode));
            newNode->val = pa->val;
            newNode->next = NULL;
            r->next = newNode;
            r = r->next;
        }
    }
    return new;
}

LNode* GetPublicNode(LinkList a, LinkList b) {
    LNode* new = (LNode*)malloc(sizeof(LNode));
    new->next = NULL;
    LNode* r = new;

    LNode* pa = a->next;
    LNode* pb = b->next;

    while (pa != NULL && pb != NULL) {
        if (pa->val == pb->val) {
            LNode* newNode = (LNode*)malloc(sizeof(LNode));
            newNode->val = pa->val;
            newNode->next = NULL;
            r->next = newNode;
            r = r->next;
        }
        else if (pa->val < pb->val)pa = pa->next;
        else pb = pb->next;
    }
    return new;
}

int main() {
    return 0;
}