#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

// typedef int ElemType;
typedef struct LNode {
    int val;
    LNode* next;
} LNode, * LinkList;

//按照升序进行元素输出。
//注意这道题并不能够取巧，必须经过遍历。因为是无序，所以并不能够知道当前元素是否为最小。
void printfLess(LinkList L) {
    if (L->next == NULL) return;

    LNode* p, * minpre;
    int min;
    while (L->next != NULL) {
        min = L->next->val;
        minpre = L;
        p = L->next;//最小初始化为第1个，所以从第2个开始。
        while (p->next != NULL) {//只读遍历
            if (p->next->val < min) {
                min = p->next->val;
                minpre = p;
            }
            p = p->next;
        }
        printf("%d ", minpre->next->val);
        minpre->next = minpre->next->next;
    }
}

//多趟找到最小元素，打印，删除。
//有头结点
void printfLess(LinkList L) {
    if (L == NULL || L->next == NULL) return;//讨论0

    int min;
    LNode* minpre, * p;
    while (L->next != NULL) {
        p = minpre = L;
        min = L->next->val;
        while (p->next != NULL) {
            if (p->next->val < min) {
                min = p->next->val;
                minpre = p;
            }
            p = p->next;
        }
        printf("%d", p->next->val);
        LNode* temp = minpre->next;
        minpre->next = temp->next;
        free(temp);
    }
}

//多趟找到最小元素，打印，删除。
//有头结点
//模型：全删除。以头结点作为判定。
//多趟找最小，要两个变量：位置和值。
void printfLess(LinkList L) {
    LNode* p, * minpre;
    int min;
    while (L->next != NULL) {
        min = L->next;
        minpre = L;
        p = L->next;//至少有1，则必有p!=NULL
        while (p->next != NULL) {//至少1个，满足。
            if (p->next->val < min) {
                min = p->next->val;
                minpre = p;
            }
        }
        printf("%d", min);
        LNode* temp = minpre->next;
        minpre->next = temp->next;
        free(temp);
    }
}

int main() {
    return 0;
}