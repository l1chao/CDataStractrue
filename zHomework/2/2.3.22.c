#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//单链表找到倒数第k个元素
int FindLastkth(LinkList L, int k) {
    LNode* slow = L, * quick = L;
    for (int i = 0;i < k && quick != NULL;i++) {
        quick = quick->next;
    }
    if (quick == NULL) return 0;
    while (quick != NULL) {
        quick = quick->next;
        slow = slow->next;
    }
    return slow->val;
}

int main() {
    return 0;
}