#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//删除有序顺序表所有重复元素。双指针方法
bool DelDuplicate(SqList* L) {
    if (L->length == 0) {
        return false;
    }

    int i, j;
    for (i = 0, j = 0;i < L->length;) { // 1,1,1,2,2,3,4,5,5,6
        if (L->data[i] != L->data[j]) {
            for (int k = i;k < L->length;k++) {
                L->data[k - (i - 1 - j)] = L->data[k];
            }
            L->length -= (i - 1 - j);
            j++;
            i = j;
        }
        else {
            i++;
        }
    }
    return true;
}

int main() {
    SqList L;
    L.length = 10;

    int testSqL[100] = { 1,1,1,2,2,3,4,5,5,6 };
    for (int i = 0;i < L.length;i++) {
        L.data[i] = testSqL[i];
    }

    for (int i = 0;i < L.length;i++) {
        printf("%d ", L.data[i]);
    }

    DelDuplicate(&L);

    for (int i = 0;i < L.length;i++) {
        printf("%d ", L.data[i]);
    }
}