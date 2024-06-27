#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

//删除最小节点。要删除还是要保留前驱节点。
void DelMin(LinkList L) {
    LNode* p = L;
    LNode* minNodepre = p;

    while (p->next != NULL) {
        if (p->next->val < minNodepre->next->val) {
            minNodepre = p;
        }
        p = p->next;
    }

    LNode* temp = minNodepre->next;
    minNodepre->next = temp->next;
    free(temp);//要删除，基本上都要用到free，free必须要的变量
}