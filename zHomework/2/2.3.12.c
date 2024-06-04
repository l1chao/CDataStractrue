#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//去除重复元素。带头结点。
void Delete_same(LinkList L) {
    LNode* p = L->next;
    for (;p->next != NULL;) {//应当将null作为节点看待，这样才是结构化的行进。
        if (p->next->val == p->val) {
            p->next = p->next->next;
        }
        else {
            p = p->next;
        }
    }
}

void Delete_same(LinkList L) {
    LNode* p = L;
    while (p->next != NULL) {
        if (p->next->val == p->val) {
            LNode* temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else {
            p = p->next;
        }
    }
}

int main() {
    return 0;
}