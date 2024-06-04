#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//判断b是否是a的子序列。
bool IsSubSeq(LinkList b, LinkList a) {
    LNode* pa = a, * pb = b;

    while (pa != NULL && pa->val != pb->val)pa = pa->next;
    if (pa == NULL) return false;

    while (pa != NULL && pb != NULL && pa->val == pb->val) {
        pa = pa->next;
        pb = pb->next;
    }

    return pb == NULL;
}

//判断b是否是a的子链
//无头结点
bool IsSubSeq(LinkList a, LinkList b) {
    LNode* pa = b, * pb = b;
    while (pa != NULL && pa->val != pb->val) pa = pa->next;
    if (pa == NULL) return false;

    while (pa != NULL && pb != NULL && pa->val == pb->val) {
        pa = pa->next;
        pb = pb->next;
    }

    return pb == NULL;
}

int main() {
    return 0;
}