#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;


void RemainPublic(LinkList a, LinkList b) {
    LNode* pa = a, * pb = b->next;
    while (pa->next != NULL && pb != NULL) {
        if (pa->next->val < pb->val) {
            pa->next = pa->next->next;
        }
        else if (pa->next->val > pb->val) {
            pb = pb->next;
        }
        else {
            pa = pa->next;
            pb = pb->next;
        }
    }
}

//应该有头结点好处理一些
LNode* RemainPublic(LinkList a, LinkList b) {
    LNode* pa = a, * pb = b;
    LNode* temp;
    while (pa->next != NULL && pb->next != NULL) {
        if (pa->next->val == pb->next->val) {
            temp = pb->next;
            pb->next = temp->next;
            free(temp);
            pa = pa->next;
        }
        else if (pa->next->val < pb->next->val) {
            temp = pa->next;
            pa->next = temp->next;
            free(temp);
        }
        else {
            temp = pb->next;
            pb->next = temp->next;
            free(temp);
        }
    }
    while (pa->next != NULL) {
        temp = pa->next;
        pa = pa->next;
        free(temp);
    }
    while (pb->next != NULL) {
        temp = pb->next;
        pb = pb->next;
        free(pb);
    }
    return a;
}

//尝试不用头结点操控两表
LNode* RemainPublic(LinkList a, LinkList b) {
    LNode* pa = a->next, * pb = b->next;

    LNode* temp, * r = a;
    while (pa != NULL && pb != NULL) {
        if (pa->val == pb->val) {
            temp = pa;
            pa = pa->next;
            temp->next = NULL;
            r->next = temp;
            r = r->next;

            temp = pb;
            pb = pb->next;
            free(temp);
        }
        else if (pa->val < pb->val) {
            temp = pa;
            pa = pa->next;
            free(temp);
        }
        else {
            temp = pb;
            pb = pb->next;
            free(pb);
        }
    }
    while (pa != NULL) {
        temp = pa;
        pa = pa->next;
        free(temp);
    }
    while (pb != NULL) {
        temp = pb;
        pb = pb->next;
        free(temp);
    }
    return a;
}

int main() {
    return 0;
}