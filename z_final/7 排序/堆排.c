#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//将k根节点树调整为大顶堆。
void HeadAdjust(int a[], int k, int len) {
    int i;
    a[0] = a[k];
    for (i = k * 2;i <= len;i *= 2) {
        if (i < len&& a[i] < a[i + 1]) i++;
        if (a[0] >= a[i])break;
        else {
            a[k] = a[i];
            k = i;
        }
    }
    a[k] = a[0];
}

void BuildMaxHeap(int a[], int len) {
    for (int i = len / 2;i > 0;i--) {
        HeadAdjust(a, i, len);
    }
}

void HeapSort(int a[], int n) {
    BuildMaxHeap(a, n);
    for (int i = n;i > 1;i--) {
        swap(&a[i], &a[1]);
        HeadAdjust(a, 1, i - 1);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    return 0;
}