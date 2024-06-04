#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//逆向打印节点的值
void ReversePrint(LinkList L) {
    if (L == NULL) {
        return;
    }
    ReversePrint(L->next);
    printf("%d", L->val);//默认数据类型是%d
}

int main() {
    return 0;
}