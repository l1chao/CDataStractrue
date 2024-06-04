#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

void Delete_from_s_to_t(LinkList L, int s, int t) {
    LNode* p = L;
    for (;p->next != NULL;) {
        if (p->next->val >= s && p->next->val <= t) {
            p->next = p->next->next;
        }
        else {
            p = p->next;
        }
    }
}

int main() {
    return 0;
}