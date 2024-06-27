#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

//交叉拆分有序链表
void SplitLink(LinkList l0, LinkList* l1, LinkList* l2) {
    LNode* p0 = l0, * p1 = *l1, * p2 = *l2;

    int parity = 0;
    while (p0->next != NULL) {
        LNode* temp = p0->next;
        p0->next = temp->next;
        temp->next = NULL;
        if ((parity + 1) % 2 == 1) {//奇数
            p1->next = temp;
            p1 = p1->next;
        }
        else {
            temp->next = p2->next;
            p2->next = temp;
        }
        p0 = p0->next;
    }
}