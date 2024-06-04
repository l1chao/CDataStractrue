//单链表各种操作
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, * LinkList;

//单链表初始化
//1. 完成了头结点赋值。2. 完成了头结点next指针null化。

bool InitLink(LinkList L) {//一般传入的是一个空变量。
    L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL) {
        print("内存不足，分配失败！");
        return false;
    }

    L->next = NULL;
    return true;
}


//（有头结点）单链表插入元素。
//思路：判断-（使者）移动-插入-（更新）
//前提：第一个元素序数为1，而不是0，有头结点。loc描述的也是序数。此时移动到第loc个节点，需要头结点指针移动loc次。
//  一般的判断是插入者和被插入者的双方检查，插入者检查是否越界，被插入者检查是否已满（被插入者为链表、且链表无length限制时，则无需检查是否已满）
//  增删之前都是先查找，要插入一个节点，先要移动到loc-1个节点。
bool InsertLink(LinkList L, int loc, int val) {
    LNode* p = GetElem(L, loc - 1);
    if (p == NULL) {
        return false;
    }

    LNode* NewNode = (LNode*)malloc(sizeof(LNode));
    NewNode->data = val;
    NewNode->next = p->next;
    p->next = NewNode;

    return true;
}

//（无头结点）单链表插入。
// 无头结点的单链表插入之所以稍微麻烦一些，是因为有头结点的链表的插入都可以“先找前驱节点再插入”，而无头结点的链表的首节点的插入无法找到前驱节点，这个时候就需要另添一条规则来解决首节点的插入。复杂的点就仅仅在这里，后面的所有节点和有头结点的都一样。换句话说，有头结点的链表仅仅是将首节点处的节点插入给优化了。
bool InsertLink_NoHead(LinkList L, int loc, int data) {
    if (loc < 1) {
        return false;
    }

    if (loc == 1) {
        LNode* NewNode = (LNode*)malloc(sizeof(LNode));
        NewNode->data = data;
        NewNode->next = L;
        L = NewNode;
        return true;
    }

    LNode* p = L;
    for (int i = 0; i < loc - 2 & p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) {
        return false;
    }

    LNode* NewNode = (LNode*)malloc(sizeof(LNode));
    NewNode->data = data;
    NewNode->next = p->next;
    p->next = NewNode;

    return true;
}

//节点后插元素。就是在指定位置节点后面插入一个节点。
//p是链表中的一个节点，所有可能有前后节点。
bool InsertNextNode(LNode* p, int val) {
    if (p == NULL) {
        return false;
    }

    //如果要插入的位置的前一个节点指针已经就位，那么直接开始置换即可。
    LNode* NewNode = (LNode*)malloc(sizeof(LNode));
    NewNode->data = val;
    NewNode->next = p->next;
    p->next = NewNode;

    return true;
}

//节点前插元素。牛哇。(思路：用后插实现前插)
bool InsertPriorNode(LNode* p, int val) {
    if (p == NULL) {
        return false;
    }

    LNode* NewNode = (LNode*)malloc(sizeof(LNode));
    NewNode->data = p->data;//要被删除的数据先要保存，所以现将p里面的数据保存到新节点里面去。
    p->data = val;

    NewNode->next = p->next;
    p->next = NewNode;

    return true;
}

//删除节点（只讨论带头结点情况）
//判断-移动-删除-释放
bool LinkDelete(LinkList L, int loc, int* e) {

    LNode* p = GetElem(L, loc - 1);
    if (p == NULL) {
        return false;
    }

    LNode* q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q); //注意标准做法应该释放内存。
    return true;
}

//用于封装寻找loc节点的操作，并检测loc合法性。以便提高简洁性和可维护性。
//注意，此时是单链表是没有最大length的，所以后不封顶。
LNode* GetElem(LinkList L, int loc) {
    if (loc < 0) {
        return NULL;
    }

    LNode* p = L;

    for (int i = 0; i < loc && p != NULL; i++) {
        p = p->next;
    }

    return p;
}

//按值查找
LNode* LocateElem(LinkList* L, int val) {
    LNode* p = L;
    for (p = p->next; p != NULL;p = p->next) {
        if (p->data == val) {
            break;
        }
    }

    return p;
}

//获取链表长度
int Length(LinkList L) {
    int len = 0;
    LNode* p = L;

    for (p = p->next; p != NULL; p = p->next) {
        len++;
    }

    return len;
}

//尾插法建立一个单链表
LinkList List_TailInsert(LinkList L) {
    int x;
    L = (LNode*)malloc(sizeof(LNode));
    LNode* r = L;
    LNode* new = L;
    scanf("%d", &x);
    while (x != 9999) {
        new = (LNode*)malloc(sizeof(LNode));
        new->data = x;
        r->next = new;// !
        r = new;
        scanf("%d", &x);
    }

    r->next = NULL;

    return L;
}

//链表的逆置


LinkList List_HeadInsert(LinkList L) {
    L = (LNode*)malloc(sizeof(LNode));
    LNode* new;
    int x;
    scanf("%d", &x);
    while (x != 9999) {
        new = (LNode*)malloc(sizeof(LNode));
        new->data = x;

        new->next = L->next;
        L->next = new;

        scanf("%d", &x);
    }

    return L;
}

int main() {
    LinkList L;
    InitLink(L);
    LNode* p = L;
}