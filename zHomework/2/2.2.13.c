#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;

//求未出现的最小正整数。
int Find(int a[], int n) {
    int i;
    int* dict = (int*)malloc(sizeof(int) * n);
    memset(dict, 0, sizeof(int) * n);

    for (i = 0;i < n;i++) {
        if (a[i] > 0 && a[i] <= n) {
            dict[a[i] - 1] = 1;
        }
    }

    for (i = 0;i < n;i++) {
        if (dict[i] == 0) {
            break;
        }
    }
    return i + 1;
}

int main() {
    return 0;
}