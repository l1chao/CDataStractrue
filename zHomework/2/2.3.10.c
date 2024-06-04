#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//将链表L分发到两个新链表a、b中去。
LNode* Redistribute(LinkList L) {
    LNode* p = L;
    // int counter = 0;//认为第一个节点序号为1。
    LNode* a = (LNode*)malloc(sizeof(LNode));//奇数
    LNode* ra = a;
    LNode* b = L;//偶数
    LNode* rb = b;

    L = L->next;
    b->next = NULL;

    while (L->next != NULL && L != NULL) {
        ra->next = L;
        ra = ra->next;
        rb->next = L->next;
        rb = rb->next;

        L->next = L->next->next;
    }
    if (L->next != NULL) ra->next = L->next;
    return a;
}

//将L中偶序数节点移动到新的带头结点的链表，并返回。注意，原链表带有头结点，并且第一个有效元素的序号为1。
LNode* TaketheEven(LinkList L) {
    LNode* new = (LNode*)malloc(sizeof(LNode));
    new->next = NULL;
    LNode* p = L;
    LNode* r = new;

    while (p->next->next != NULL && p->next != NULL) {
        r->next = p->next->next;
        r = r->next;
        r->next = NULL;
        p->next->next = p->next->next->next;
        p = p->next;
    }

    return new;
}

//奇偶分家罢了
//有头结点。
LNode* SplitByOdevity(LinkList L) {
    if (L->next == NULL) return NULL;

    LNode* new = (LNode*)malloc(sizeof(LNode));
    LNode* r = new;
    new->next = NULL;

    LNode* p = L;
    while (p->next != NULL && p->next->next != NULL) {
        LNode* temp = p->next->next;
        p->next->next = temp->next;
        temp->next = NULL;
        r->next = temp;
        r = temp;

        p = p->next;
    }
    return new;//偶数链，带头结点。
}

LNode* SplitByOdevity(LinkList L) {
    if (L == NULL || L->next == NULL) return NULL;

    LNode* new = (LNode*)malloc(sizeof(LNode));
    new->next = NULL;
    LNode* r = new;//尾指针

    LNode* p = L;
    while (p->next != NULL && p->next->next != NULL) {
        LNode* temp = p->next->next;
        p->next->next = temp->next;
        temp->next = NULL;

        r->next = temp;
        r = r->next;
    }
}
int main() {
    return 0;
}