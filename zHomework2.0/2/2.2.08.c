#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//A[m+n]里面按顺序存储数列a(a1,a2...am)和数列b(b1,b2...bn)现在将a和b数列整体换位置。双倒序。
void DoubleTraverse(SqList* l, int m, int n) {
    Traverse(l, 0, m - 1);
    Traverse(l, m, n + m - 1);
    Traverse(l, 0, n + m - 1);
}

bool Traverse(SqList* l, int head, int end) {
    if (head<0 || end >l->length - 1) {
        return false;
    }

    int mid = (head + end) / 2; // 关于中点的问题。
    for (int k = 0;k <= mid;k++) {
        int temp = l->data[k];
        l->data[k] = l->data[l->length - 1 - k];
        l->data[l->length - 1 - k] = temp;
    }
}