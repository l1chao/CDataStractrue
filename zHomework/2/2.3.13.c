#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//假设有头结点。a和b序列升序，要求将两个链表按照合并，且合并后为降序。
//注意，b链头结点在调用此函数后后续节点为null。
void Merge(LinkList a, LinkList b) {
    LNode* pa = a->next;
    LNode* pb = b->next;
    LNode* temp;
    a->next = NULL;

    while (pa != NULL && pb != NULL) {
        if (pa->val < pb->val) {
            temp = pa;
            pa = pa->next;
            temp->next = a->next;
            a->next = temp;
        }
        else {
            temp = pb;
            pb = pb->next;
            temp->next = a->next;
            a->next = temp;
        }
    }
    while (pa != NULL) {
        temp = pa;
        pa = pa->next;
        temp->next = a->next;
        a->next = temp;
    }
    while (pb != NULL) {
        temp = pb;
        pb = pb->next;
        temp->next = a->next;
        a->next = temp;
    }
}

//升序双链升序归并。归并到a链上去。
//讲真，上面的解法也会改变元素之间的指针，那还不如就用这种方法。这种方法和数组的归并是大不一样的，因为数组的方法是紧密排列的，和链表不同。
//带头结点。
//注意，局部是pb全删除。
void Merge_inplace(LinkList a, LinkList b) {
    LNode* pa = a, * pb = b;
    while (pa->next != NULL && pb->next != NULL) {
        if (pa->next->val <= pb->next->val) pa = pa->next;
        else {
            LNode* temp = pb->next;
            pb->next = temp->next;
            temp->next = pa->next;
            pa->next = temp;
        }
    }

    if (pb->next != NULL) {
        pa->next = pb->next;
    }
}

int main() {
    return 0;
}