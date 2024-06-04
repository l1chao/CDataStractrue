#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;

void Rerverse(SqList* L, int start, int end) {
    int temp;
    for (int i = start; i < (end - start + 1) / 2 + start;i++) {
        temp = L->data[i];
        L->data[i] = L->data[start + end - i];
        L->data[start + end - i] = temp;
    }
}
int main() {


    return 0;
}