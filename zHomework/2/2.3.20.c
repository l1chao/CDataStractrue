#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    int val;
    LNode* next;
    LNode* pre;
    int freq;
} LNode, * LinkList;

//这个思路大概也差不多。
LNode* Locate(LinkList L, int x) {
    LNode* p = L->next;
    //先删除后插入。
    while (p != NULL && p->val != x) p = p->next;
    if (p == NULL) return NULL;

    p->freq++;
    LNode* temp = p;
    if (temp->next != NULL) temp->next->pre = temp->pre;
    p->next = p->next->next;

    LNode* newp = p;
    while (newp != L && newp->pre->freq <= p->freq) {
        newp = newp->pre;
    }
    if (newp->next != NULL) newp->next->pre = temp;
    temp->next = newp->next;
    temp->pre = newp;
    newp->next = temp;

    return temp;
}


int main() {
    return 0;
}