#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;

//顺序表 删除的快捷方法一般是填充。
bool del_s_to_t(SqList* L, ElemType s, ElemType t) {
    if (L->length == 0 || s >= t) {
        return false;
    }

    //像第3题一样即可。
    int k = 0, i = 0;
    for (;i < L->length;i++) {
        if (L->data[i] < s && L->data[i] > t) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
    return true;
}

bool del_s_to_t(SqList* L, ElemType s, ElemType t) {
    if (s > t || L->length == 0) {
        return false;
    }

    int k = 0, i;//k实际上指向第一个可以插入的位置，那么结束后k将会指向len而不是len-1的位置。
    for (i = 0;i < L->length;i++) {
        if (L->data[i] < s || L->data[i] >t) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
    return true;
}

int main() {


    return 0;
}