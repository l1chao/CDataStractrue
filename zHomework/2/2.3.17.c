#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
    LNode* pre;
} LNode, * LinkList;

//判断链表是否对称
//抗0、1

//判断带头结点循环双链表是否对称。
bool IsSymmetrical(LinkList L) {
    LNode* head = L->next, * tail = L->pre;
    while (tail->next != head && head != tail) {
        if (head->val != tail->val) return false;
        head = head->next;
        tail = tail->pre;
    }

    return true;
}

int main() {
    return 0;
}