#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

// typedef int ElemType;
typedef struct LNode {
    int val;
    struct LNode* next;
} LNode, * LinkList;

//无头结点////////////////////////////////////////////////////////////////
LNode* CreateLink() {
    LNode* new = (LNode*)malloc(sizeof(LNode));
    LNode* tail = new;
    int temp;

    //输入数组
    int input[8] = { 2,4,5,1,3,8,7,6 };
    int LinkLength = 8;

    for (int i = 0;i < LinkLength;i++) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        // scanf("%d", &temp);
        // newNode->val = temp;
        newNode->val = input[i];
        tail->next = newNode;
        tail = tail->next;
    }
    tail->next = NULL;//尾置空

    LNode* p = new->next;
    free(new);
    return p;//去掉头结点。
}


void ReversePrint(LinkList L) {
    if (L == NULL) {
        return;
    }
    ReversePrint(L->next);
    printf("%d", L->val);//默认数据类型是%d
}

void InsertSortonLink(LinkList L) {
    for (LNode* pre = L->next;pre->next != NULL;) {
        LNode* p = L;
        for (;p->next->val < pre->next->val;) {//不稳定
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

void Delete_x(LinkList L, int x) {
    LNode* p = L;
    while (p->next != NULL) {
        if (p->next->val == x) {
            p->next = p->next->next;
        }
        else p = p->next;
    }
}

void LinkReverse(LinkList L) {
    LNode* pre = L->next;
    while (pre->next != NULL) {// 删除则pre不移动。
        LNode* temp = pre->next;
        pre->next = temp->next;
        temp->next = L->next;
        L->next = temp;
    }
}

int FindLastkth(LinkList L, int k) {
    LNode* slow = L, * quick = L;
    for (int i = 0;i < k && quick != NULL;i++) {
        quick = quick->next;
    }
    if (quick == NULL) return 0;
    while (quick != NULL) {
        quick = quick->next;
        slow = slow->next;
    }
    return slow->val;
}

//找到偶中左左
LNode* findMid(LinkList L) {
    if (L->next == NULL) return NULL;

    LNode* slow = L, * quick = L;
    while (quick->next->next != NULL && quick->next->next->next != NULL) {//抗1
        slow = slow->next;
        quick = quick->next->next;
    }
    return slow;
}


void Printless(LinkList L) {//抗0,1，不抗非法。
    int min;
    LNode* minpre, * temp, * p;
    while (L->next != NULL) {
        min = L->next->val;
        minpre = L;
        p = L->next;
        while (p->next != NULL) {
            if (p->next->val < min) {
                min = p->next->val;
                minpre = p;
            }
            p = p->next;
        }

        printf("%d\n", min);
        temp = minpre->next;
        minpre->next = temp->next;
        free(temp);
    }
}

int main() {
    LNode* L = CreateLink();
    // Del_x(L, 2);

    //添加头结点
    LNode* NewHead = (LNode*)malloc(sizeof(LNode));
    NewHead->next = L;
    L = NewHead;

    //添加尾循环
    // LNode* p = L;
    // while (p->next != NULL)p = p->next;
    // p->next = L;

    // Del_Min(L);
    // ReversePrint(L);
    // LinkReverse(L);
    // InsertSortonLink(L);
    // printfLess(L);
    // DestroyPrint(L);
    // int i = FindLastkth(L, 4);
    // LNode* slow = findMid(L);
    Printless(L);
    return 0;
}