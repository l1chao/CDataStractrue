//快速排序
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int Partition(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}


void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);//找到中点+以此为分割点。
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}
int main() {


    return 0;
}