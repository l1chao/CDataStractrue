#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    LNode* next;
} LNode, * LinkList;

//寻找公共节点。这个算法值得深入研究。
//认为无头结点。说实话，这个算法的简洁性有非常值得借鉴的地方。
LNode* findPublicNode(LinkList l1, LinkList l2) {
    LNode* p1 = l1;
    LNode* p2 = l2;
    if (l1 == NULL || l2 == NULL) return NULL;

    // while (p1 != p2) {
    //     if (p1->next == NULL && p2->next != NULL) {
    //         p1 = l2;
    //         p2 = p2->next;
    //     }
    //     if (p1->next != NULL && p2->next == NULL) {
    //         p2 = l1;
    //         p1 = p1->next;
    //     }
    //     if (p1->next != NULL && p2->next != NULL) {
    //         p1 = p1->next;
    //         p2 = p2->next;
    //     }


    // }
    while (p1 != p2) {
        if (p1 == NULL) p1 = l2;
        else p1 = p1->next;

        if (p2 == NULL) p2 = l1;
        else p2 = p2->next;
    }
    return p1;
}

//这道题有两种方法，一种是通过移动长链指针使得两条链尾对齐；一种是尾连接指针移动。简单来说如果题目首先告诉了两条链的长度，肯定选第一种方法，因为第一种的第1次遍历是为了得到两个链的长度。如果没有事先告诉两条链的差别，两种方法实际上差不多——从代码看，第2种还要简洁的多。
LNode* FindthePublic(LinkList a, LinkList b) {
    //认为无头结点
    if (a == NULL || b == NULL) return a;
    LNode* pa = a, * pb = b;
    while (pa != pb) {//巧妙的方法是综合的结果。
        if (pa == NULL) pa = b;//这里面的4个判断是从每一步两个指针的角度来考虑的。
        else pa = pa->next;

        if (pb == NULL)pb = a;
        else pb = pb->next;
    }
    return pa;
}

int main() {
    return 0;
}