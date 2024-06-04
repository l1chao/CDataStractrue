#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int* data[100];
    int length;
} SqList;

bool DeleteMin(SqList* L, int* e) {
    if (L->length == 0) {
        return false;
    }

    *e = L->data[0];
    int loc = 0;
    for (int j = 1;j < L->length;j++) { //循环的始末位置，一般都是按照最正常的流程来看的。如果只是1个单位的变动，一般结束约束不会错误。
        if (L->data[j] < *e) {
            *e = L->data[j];
            loc = j;
        }
    }

    L->data[loc] = L->data[L->length - 1];
    L->length--;

    return true;
}

bool DelMin(SqList* L, int* e) {
    if (L->length == 0) {
        return false;
    }

    *e = L->data[0];
    int loc = 0;
    for (int i = 1;i < L->length;i++) {
        if (L->data[i] < *e) {
            *e = L->data[i];
            loc = i;
        }
    }

    L->data[loc] = L->data[L->length - 1];
    L->length--;
    return true;
}