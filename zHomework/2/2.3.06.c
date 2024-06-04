#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//对带有头结点的单链表排序。
//单链表常用的排序方法：直接插入、选择排序、快排、冒泡。这里因为直接插入相对于选择排序会少很多比较（选择排序都会完全比较），所以选择插入排序。这里的插入排序没有像数组一样从有序序列的尾部向前面遍历，而是从头部遍历。
//例子跑通！
void InsertSortonLink(LinkList L) {
    for (LNode* pre = L->next;pre->next != NULL;) {
        LNode* p = L;
        for (;p->next->val < pre->next->val;) {//简单但是不稳定。可以复杂一点但是稳定吗？
            p = p->next;
        }
        if (pre == p) pre = pre->next;
        else {
            LNode* temp = pre->next;
            pre->next = temp->next;
            temp->next = p->next;
            p->next = temp;
        }
    }
}

//本质上还是一个删除遍历，所以要觉得什么时候删除什么时候移动。
void InsertSortonLink(LinkList L) {
    if (L->next == NULL) return;
    LNode* pre = L->next;
    while (pre->next != NULL) {//为什么要用前驱？删除就要用前驱。
        LNode* p = L;
        while (p->next->val < pre->next->val) p = p->next;//有序+单位移动，肯定不报错。
        if (p == pre) pre = pre->next;
        else {
            LNode* temp = pre->next;
            pre->next = temp->next;
            temp->next = p->next;
            p->next = temp;
        }
    }
}

//能不能稍微麻烦一点，但是能够保证稳定性？好像能。
void InserSortonLink(LinkList L) {
    LNode* pre = L;
    while (pre->next != NULL) {
        LNode* p = L;
        //找到第一个大于pre.n.v的元素，但是遇到pre.n就pre++考察下一元素。
        while (p->next->val <= pre->next->val) {
            if (p == pre) {
                pre = pre->next;
                break;
            }
            p = p->next;
        }
        if (p->next == pre) {
            LNode* temp = pre->next;
            pre->next = temp->next;
            temp->next = p->next;
            p->next = temp;
        }
    }
}
void InsertSortonLink(LinkList L) {
    for (LNode* pre = L->next;pre->next != NULL;) {
        LNode* p = L;
        for (;p->next->val < pre->next->val;) p = p->next;
        if (pre == p) pre = pre->next;
        else {
            LNode* temp = pre->next;
            pre->next = pre->next->next;
            temp->next = p->next;
            p->next = temp;
        }
    }
}

void InsertSortonLink(LinkList L) {
    LNode* head = L->next;
    L->next = NULL;

    for (;head != NULL;) {
        for (LNode* p = L;;) {
            if (p->next == NULL || p->next->val > head->val) {
                LNode* temp = head;
                head = head->next;
                temp->next = p->next;
                p->next = temp;
                break;
            }
        }
    }
}

int main() {

    return 0;
}