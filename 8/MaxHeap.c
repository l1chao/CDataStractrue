//堆排序
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//将k根节点树调整为大顶堆。
void HeadAdjust(int a[], int k, int len) {
    a[0] = a[k];
    for (int i = 2 * k;i <= len;i *= 2) {
        if (i < len && a[i] < a[i + 1]) i++;
        if (a[0] < a[i]) {
            a[k] = a[i];
            k = i;
        }
        else break;
    }
    a[k] = a[0];
}

void BuildMaxHeap(int a[], int len) {
    for (int i = len / 2;i >= 1;i--) {
        HeadAdjust(a, i, len);
    }
}

void HeapSort(int a[], int len) { //得到升序序列
    BuildMaxHeap(a, len);
    for (int i = len;i > 1;i--) {
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
    int A[9] = { 0,87,45,78,32,17,65,53,9 };
    HeapSort(A, 8);
    for (int i = 1; i < 9;i++) {
        printf("%d ", A[i]);
    }

    return 0;
}