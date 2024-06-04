#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//销毁带头结点的循环单链表，并升序输出。
void DestroyPrint(LinkList L) {
    LNode* p = L;
    int min;
    LNode* minpre, * temp;

    while (L->next != L) {
        p = L->next;
        min = L->next->val;
        minpre = L;
        while (p->next != L) {
            if (p->next->val < min) {
                min = p->next->val;
                minpre = p;
            }
            p = p->next;
        }

        printf("%d", min);
        temp = minpre->next;
        minpre->next = temp->next;
        free(temp);
    }
    free(L);
}

int main() {
    return 0;
}