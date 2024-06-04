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

    int arr[] = { 2,9,3,7,4,5,4,3,1 };
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
LinkList List_TailInsert() {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    LNode* p = L;
    int arr[] = { 2,9,3,7,4,5,4,3,1 };
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0;i < arrlen;i++) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        newNode->val = arr[i];
        newNode->next = NULL;

        p->next = newNode;
        p = p->next;
    }
    return L;
}

//查值。返回第一个x的节点。
LNode* FindValue(LinkList L, int x) { //链表遍历。
    LNode* p = L->next;

    for (;p != NULL && p->val != x;p = p->next) {}

    return p;
}

//查序，返回对应结点
//链表的查询i方法：以L为0L.next为1，设置一个整数记录0,1等，使得整数与指针同时变换，这样就能够通过检测整数来检测指针了。
LNode* FindLoc(LinkList L, int loc) { //为什么是返回结点？如果节点里面数据很多，确实返回节点是正确的。
    if (loc < 1)return NULL;

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

//删除指定位置的节点
bool Delete(LinkList L, int loc, int* val) {
    if (loc < 1) {
        return false;
    }
    LNode* p = L;
    int locp = 0;

    // for (;p->next != NULL && locp < loc - 1;p = p->next, locp++) {}

    // if (p->next == NULL) {
    //     return false;
    // }

    for (;locp < loc - 1;p = p->next, locp++) {
        if (p->next == NULL) {
            return false;
        }
    }

    LNode* temp = p->next;
    *val = temp->val;
    p->next = temp->next;
    free(temp);

    return true;
}

//求表长
int ListLen(LinkList L) {
    int locp = 0;
    LNode* p = L;
    for (;p->next != NULL;p = p->next, locp++) {}

    return locp;
}

//测试
int main() {
    LNode* L = List_TailInsert();//空指针作为函数参数传递的时候，2,9,3,7,4,5,4,3,1


    // LNode* p = FindLoc(L, 0);
    // printf("%d\n", p->val);

    // p = FindLoc(L, 1);
    // printf("%d\n", p->val);

    // p = FindLoc(L, 2);
    // printf("%d\n", p->val);

    // p = FindLoc(L, 5);
    // printf("%d\n", p->val);

    //查值测试
    // LNode* p = FindValue(L, 9);
    // printf("%d\n", p->val);

    //查序测试 2,9,3,7,4,5,4,3,1
    // LNode* p = FindLoc(L, 2);
    // if (p != NULL)
    //     printf("%d", p->val);
    // else
    //     printf("不存在！");
    // p = FindLoc(L, 0);
    // if (p != NULL)
    //     printf("%d", p->val);
    // else
    //     printf("不存在！");
    // p = FindLoc(L, 100);
    // if (p != NULL)
    //     printf("%d", p->val);
    // else
    //     printf("不存在！");

    //插入测试
    // Insert(L, 3, 9527);
    // printf("%d\n", FindLoc(L, 3)->val);

    //删除测试 2,9,3,7,4,5,4,3,1
    // int loc = 3;
    // int val = 0;
    // printf("%d\n", FindLoc(L, loc)->val);
    // Delete(L, loc, &val);
    // printf("%d\n", val);
    // printf("%d\n", FindLoc(L, loc)->val);

    //表长测试
    // printf("%d", ListLen(L));


}