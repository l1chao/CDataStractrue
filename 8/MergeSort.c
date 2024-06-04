//归并排序
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 10 //A[]的长度为N


int B[N] = { 0 };

//排序什么的一般都是在顺序结构里面进行的，而较少在链表中进行。
void Merge(int A[], int low, int mid, int high) {
    int i, j, k;
    for (i = low; i <= high; i++) {//将即将排序的对象复制到B里面去。最终完成的是在A里面的排序。
        B[i] = A[i];
    }

    for (i = low, j = mid + 1, k = i;i <= mid && j <= high;k++) {
        if (B[i] <= B[j]) {
            A[k] = B[i];
            i++;
        }
        else {
            A[k] = B[j];
            j++;
        }
    }
    while (i <= mid) {
        A[k] = B[i];
        k++;
        i++;
    }
    while (j <= high) {
        A[k] = B[j];
        k++;
        j++;
    }
}

void Merge(int A[], int low, int mid, int high) {
    int i, j, k;
    for (i = low;i <= high;i++) {
        B[i] = A[i];
    }

    for (i = k = low, j = mid + 1;i <= mid && j <= high;k++) {
        if (B[i] < B[j]) {
            A[k] = B[i];
            i++;
        }
        else {
            A[k] = B[j];
            j++;
        }
    }
    for (;i <= mid;i++, k++) A[k] = B[i];
    for (;j <= mid;j++, k++) A[k] = B[j];
}
// int* B = (int*)malloc(N * sizeof(int));

void MergeSort(int A[], int low, int high) {
    if (low < high) {//如果low==high则不会继续排序。
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int main() {


    return 0;
}