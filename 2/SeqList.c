//顺序表相关操作

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 100

typedef struct {
    int a[MaxSize];
    int len;
} SqList;

//插入操作
bool ListInsert(SqList* L, int i, int e) { //看来 这个地方i是位序
    if (i<1 || i>L->len + 1 || L->len == MaxSize) {
        return false;
    }

    for (int j = i - 1;j <= L->len - 1;j++) {
        L->a[j + 1] = L->a[j];
    }

    L->a[i - 1] = e;
    L->len++;//结构体整体更新

    return true;
}

//按位删
bool ListDelete(SqList* L, int i, int* e) {
    if (i<1 || i>L->len) { //按位删除只需要考虑i在不在范围里面即可
        return false;
    }

    *e = L->a[i - 1];
    for (int j = i;j <= L->len - 1;j++) {
        L->a[j - 1] = L->a[j];
    }

    L->len--;

    return true;
}

//按值查。顺序表本身支持随机访问，所以按位查是天然已经实现了的。
int LocateElem(SqList* L, int e) {
    for (int i = 0; i < L->len;i++) {
        if (L->a[i] == e) {
            return i + 1; //返回的是位序不是下标。
        }
    }
    return 0;
}




int main() {


    return 0;
}