#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//顺序表删除关键字值在s与t(s<t)之间的数据元素。注意健壮性。
bool DelStoT(SqList* L, int s, int t) {
    if (L->length == 0 || s > t) {
        return false;
    }

    int k = 0;
    for (int i = 0;i < L->length;i++) {
        if (L->data[i] >= s && L->data[i] <= t) {
            k++;
        }
        else {
            L->data[i - k] = L->data[i];
        }
    }

    return true;
}



//有序表删除[s,t]内元素。
bool DelStoT1(SqList* L, int s, int t) {
    if (L->length == 0 || s > t) {
        printf("L is empty or s>t");
        return false;
    }

    int head, tail;
    for (head = 0;head < L->length && L->data[head] < s;head++);
    for (tail = head + 1; tail < L->length && L->data[tail] <= t;tail++);

    int distance = tail - head;
    for (int i = tail;i < L->length;i++) {
        L->data[i - distance] = L->data[i];
    }
    L->length -= distance;

    return true;
}

int main() {
    SqList L;

    int testSqL[11] = { 2,4,99,1,3,5,6,22,7,8,10 };//自定义1
    L.length = sizeof(testSqL) / sizeof(testSqL[0]);
    for (int i = 0;i < L.length;i++) {
        L.data[i] = testSqL[i];
    }

    if (DelStoT(&L, 4, 8)) {
        for (int i = 0;i < L.length;i++) {
            printf("%d ", L.data[i]);
        }
        printf("delete successfully!");
    }

    printf("delete !");
    return 0;
}