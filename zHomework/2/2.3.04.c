#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//带头结点删除最小值
void Del_Min(LinkList L) {
    LNode* pre = L;//注意，可能第一个节点就是最小值，所以pre要放在L上面。
    int min = L->next->val;
    for (LNode* p = L->next; p->next != NULL;p = p->next) {
        if (p->next->val < min) {
            min = p->next->val;
            pre = p;
        }
    }

    //下面这几步都是删除节点的经典步骤了。
    LNode* temp = pre->next;
    pre->next = temp->next;
    free(temp);
    return;
}

int main() {
    return 0;
}