#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//详见11题描述，其实是10题的稍微改动版本。
//抗0、1
LNode* AdvanceOf10(LinkList L) {
    LNode* new = (LNode*)malloc(sizeof(LNode));
    new->next = NULL;
    LNode* p = L;
    LNode* temp;
    while (p->next != NULL && p->next->next != NULL) {
        temp = p->next->next;
        p->next->next = temp->next;
        temp->next = new->next;
        new->next = temp;
        p = p->next;
    }
    return new;
}

int main() {
    return 0;
}