#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//将两个有序顺序表和成为一个新的有序顺序表，并返回。
//在C++里面，如果返回的东西比较大比较复杂如结构体，可以在参数里面返回。
bool Combine(SqList* a, SqList* b, SqList* c) {
    if (a->length + b->length > c->length) {
        return false;
    }

    int i, j, k;
    for (i = 0, j = 0, k = 0;i < a->length && j < b->length;k++) {
        if (a->data[i] < b->data[j]) {
            c->data[k] = a->data[i];
            i++;
        }
        else {
            c->data[k] = b->data[j];
            j++;
        }
    }

    if (i == a->length) {
        for (;j < b->length;j++, k++) {
            c->data[k] = b->data[j];
        }
    }
    else {
        for (;i < a->length;i++, k++) {
            c->data[k] = a->data[i];
        }
    }
    c->length = k;
    return true;
}