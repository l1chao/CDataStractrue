#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;
//算法基本思想：设置快慢指针，两者移动速率为2倍关系。如果有环，则一定会出现快慢指针重合的情况；如果无环则最后一定会遍历到末尾NULL处。

void IsCircle(LinkList L) {
    LNode* slow = L, * quick = L;
    while (quick->next != NULL && quick != NULL) {
        if (slow == quick) return true;
        slow = slow->next;
        quick = quick->next->next;
    }
    return false;
}

//无头结点
void IsCircle(LinkList L) {
    LNode* slow = L, * quick = L;
    while (quick->next != NULL && quick->next->next != NULL) {
        if (quick == slow) return true;
        slow = slow->next;
        quick = quick->next->next;
    }
    return false;
}

int main() {
    return 0;
}