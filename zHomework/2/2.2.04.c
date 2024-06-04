#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;


bool del_s_to_t(SqList* L, ElemType s, ElemType t) {
    if (L->length == 0 || s > t) {
        return false;
    }

    int head, tail;
    for (;head < L->length && L->data[head] < s;head++) {}
    for (tail = head; tail < L->length && L->data[tail] <= t;tail++) {}
    if (head == tail) return false;

    for (;tail < L->length;tail++, head++) {
        L->data[head] = L->data[tail];
    }
    L->length = head;
    return true;
}

//删除所有满足s<=x<=t的x。
void Del_from_s_to_t(SqList* L, ElemType s, ElemType t) {
    if (L->length == 0 || s > t) return false;

    int head, tail;
    for (head = 0;head < L->length && L->data[head] < s; head++) {}
    for (tail = 0;tail < L->length && L->data[tail] <= t; tail++) {}
    if (tail == head) return false;

    for (;head < L->length;head++, tail++) {
        L->data[head] = L->data[tail];
    }

    L->length = head;
    return true;
}

int main() {


    return 0;
}