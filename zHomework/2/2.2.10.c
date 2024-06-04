#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;

//左移p个，则移动后第一个元素下标为p。
void LeftRotate(int a[], int p, int length) {
    Rerverse(a, 0, p - 1);
    Rerverse(a, p, length - 1);
    Rerverse(a, 0, length - 1);
}

void Rerverse(int* L, int start, int end) {
    int temp;
    for (int i = start; i < (end - start + 1) / 2 + start;i++) {
        temp = L[i];
        L[i] = L[start + end - i];
        L[start + end - i] = L[i];
    }
}
int main() {
    return 0;
}