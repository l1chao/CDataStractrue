//简单选择排序
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

void swa(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SelectSort(int a[], int n) {
    int i, j, min, minLoc;
    for (i = 0;i < n - 1;i++) {//为什么是n-1（倒数第二个）？因为倒数第二个排完就不用排了。
        min = a[i];
        minLoc = i;
        for (j = i + 1;j < n;j++) {//i+1是因为上面那个min占用了一个，而且不会出错。
            if (a[j] < min) {
                min = a[j];
                minLoc = j;
            }
        }
        swa(&a[i], &a[minLoc]);
    }
}

void SelectSort(int a[], int n) {
    int i, j, min, minLoc;
    for (i = 0;i < n - 1;i++) {
        min = a[i];
        minLoc = i;
        for (j = i + 1;j < n;j++) {
            if (a[j] < min) {
                min = a[j];
                minLoc = j;
            }
        }
        swa(&a[i], &a[minLoc]);
    }
}


int main() {
    int A[10] = { 27,12,38,97,76,49,65,49 };
    SelectSort(A, 8);
    for (int i = 0;i < 8;i++) {
        printf("%d ", A[i]);
    }

    return 0;
}