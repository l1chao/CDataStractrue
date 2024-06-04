#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

void InsertSort(int a[], int n) {
    int i, j;

    for (i = 2;i < n;i++) {
        a[0] = a[i];
        for (j = i - 1;a[j] > a[0];j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = a[0];
    }
}

void InsertSort(int a[], int n) {
    int i, j, temp;
    for (i = 1;i < n;i++) {
        temp = a[i];
        for (j = i - 1;j > 0 && a[j] > temp;j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

int InsertLoc(int a[], int low, int high, int key) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key)return mid + 1;
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

void InserSort_advance(int a[], int n) {
    int i, j, temp, loc;
    for (i = 1;i <= n;i++) {
        loc = InsertLoc(a, 0, i - 1, a[i]);
        for (j = i - 1;j >= loc;j--) {
            a[j + 1] = a[j];
        }
        a[loc] = a[i];
    }
}

//对于折半查找改善的直接插入，low就是元素插入位置

int main() {


    return 0;
}