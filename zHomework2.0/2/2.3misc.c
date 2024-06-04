#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

//循环输入数值，头插法建立链表。
LinkList List_HeadInsert() {
    LNode* L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    int arr[] = { 2,9,3,7,4 };
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0;i < arrlen;i++) {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        p->val = arr[i];
        p->next = L->next;
        L->next = p;
    }

    return L;
}

//循环输入数值，尾插法建立链表
LinkList List_TailInsert(LinkList L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    LNode* p = L;
    int input;
    scanf("%d", &input);
    while (input != 9999) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        newNode->val = input;
        newNode->next = NULL;

        p->next = newNode;
        p = p->next;

        scanf("%d", &input);
    }
}

//查值。返回第一个x。
bool FindValue(LinkList L, int x, int* loc) { //链表遍历。
    LNode* p = L;

    int locAcc = 0;
    for (;p->next != NULL;p = p->next) {
        if (p->val == x) {
            *loc = locAcc;
            return true;
        }
        locAcc++;
    }
    return false;
}

//查序，返回对应结点
// 链表的查询i方法：以L为0L.next为1，设置一个整数记录0,1等，使得整数与指针同时变换，这样就能够通过检测整数来检测指针了。
LNode* FindLoc(LinkList L, int loc) { //为什么是返回结点？如果节点里面数据很多，确实返回节点是正确的。
    LNode* p = L;
    int locp = 0;

    for (;p != NULL && locp < loc;p = p->next, locp++) {}

    return p;
}

//增添结点到第i个（结点从第1个开始）
// 添加/删除和查序不同，查序查的是本身，添加/删除要找的是前驱。
bool Insert(LinkList L, int loc, int val) { //注意这里的loc实际上
    if (loc < 1) {
        return false;
    }

    int locp = 0;
    LNode* p = L;

    for (;p->next != NULL && locp < loc - 1;p = p->next, locp++) {}//这里是要找待删除元素的前驱。退出的时候是locp == loc - 1

    if (p->next != NULL) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        newNode->val = val;
        newNode->next = p->next;
        p->next = newNode;

        return true;
    }

    return false;
}

//如何随链表遍历来一起计数？



//测试
int main() {
    LNode* L = List_HeadInsert();//空指针作为函数参数传递的时候，

    LNode* p = FindLoc(L, 0);
    printf("%d\n", p->val);

    p = FindLoc(L, 1);
    printf("%d\n", p->val);

    p = FindLoc(L, 2);
    printf("%d\n", p->val);

    p = FindLoc(L, 5);
    printf("%d\n", p->val);
}