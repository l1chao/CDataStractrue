//直接插入排序算法
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//排序思路：从第2个元素开始遍历，将前面所有比当前元素大的后移一位，最后将这个元素插入到前面空出来的位置。
void InserSort(int a[], int n) {
    int i, j, temp;
    for (i = 1;i < n;i++) {
        temp = a[i];
        for (j = i - 1;j >= 0 && a[j] > temp;j--) {//对所有a[j]>temp的元素进行后移操作。后移操作只需要对>temp的元素进行操作。
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

//有哨兵版本，此时元素下标从1开始，0下标用于存储temp
void InsertSort_InnerPoint(int a[], int n) {
    int i, j;
    for (i = 2;i <= n;i++) {
        a[0] = a[i];
        for (j = i - 1;a[j] > a[0];j--) {//此时少了一个判断，微微提升了性能。
            a[j + 1] = a[j];
        }
        a[j + 1] = a[0];
    }
}

void InsertSort_half(int A[], int n) {
    int i, j, low, mid, high, loc;
    for (i = 2;i < n;i++) {
        A[0] = A[i];

        //折半查找
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] <= A[0]) low = mid + 1;
            else high = mid - 1;
        }

        for (j = i - 1;j >= low;j--) {//把low到i-1的所有元素后移一个位置。
            A[j + 1] = A[j];
        }
        A[low] = A[0];
    }
}

//置i于loc
int InsertAtLoc(int a[], int loc, int i) {
    //loc,i-1
    int temp = a[i];
    for (int p = i - 1;p >= loc;p--) {
        a[p + 1] = a[p];
    }
    a[loc] = temp;
}

//将i,j后移位
int ans(int a[], int i, int j) {
    int p;
    for (p = j;p >= i;p--) {
        a[p + 1] = a[p];
    }
    return 1;
}

//后移k位
void ans(int a[], int low, int high, int k) {
    for (int p = high;p >= low;p--) {
        a[p + k] = a[p];
    }
}

int main() {

    return 0;
}