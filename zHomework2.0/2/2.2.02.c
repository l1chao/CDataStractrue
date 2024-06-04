#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

// 将顺序表L逆置，要求空间复杂度为O(1)
void ReverseSeq(SqList* L) {
    int mid = L->length / 2;
    for (int i = 0;i <= mid;i++) {
        int temp = L->data[i];
        L->data[i] = L->data[L->length - 1 - i];
        L->data[L->length - 1 - i] = temp;
    }

    return;
}

int main() {
    SqList L; //此时已经开辟内存了。c的声明有点混乱，变量声明的时候就已经开辟内存了，这一点和Go不一样。
    for (int i = 0;i < L.length;i++) {
        L.data[i] = i + 1;
    }
    L.length = 6;

    ReverseSeq(&L);
    for (int i = 0;i < L.length;i++) {
        printf("%d\n", L.data[i]);
    }

    return 0;
}