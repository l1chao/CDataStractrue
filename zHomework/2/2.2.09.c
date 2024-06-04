#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;

//查找算法昨天总结了，三大种：顺序、折半、散列。这里说更快，实际上就是折半和散列；散列不适合，所以就是折半。
void findElem(SqList* L, ElemType e) {
    //先折半查找，找到则和后一个元素进行交换；没有找到则插入。
    int loc = -1; //loc是下标
    if (BinaryFind(L, e, &loc)) {
        int temp = L->data[loc];
        L->data[loc] = L->data[loc + 1];
        L->data[loc + 1] = temp;
    }
    else {
        for (int i = L->length;i > loc;i--) {
            L->data[i] = L->data[i - 1];
        }
        L->data[loc] = e;
    }
}

//有序列表寻找元素e，如果找到返回e的位置；如果找不到，则返回如果需要非破坏插入的位置（即插入后不破坏递增顺序）
bool BinaryFind(SqList* L, ElemType e, int* loc) {
    int low = 0, high = L->length - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L->data[mid] == e) {
            *loc = mid;
            return true;
        }
        else if (L->data[mid] < e) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    *loc = low;
    return false;
}

bool BinaryFind(SqList* L, ElemType e, int* loc) {//结构：三个指针。
    int low = 0, high = L->length, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L->data[mid] == e) {
            *loc = mid;
            return true;
        }
        else if (L->data[mid] < e) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    *loc = low;
    return false;
}

//二分查找，要求返回是否查找成功，若成功返回元素下标；若失败返回元素无破坏插入应该插入的位置。
bool BinarySearch(SqList* L, ElemType e, int* loc) {
    int low = 0, high = L->length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L->data[mid] == e) {
            *loc = mid;
            return true;
        }
        else if (L->data[mid] < e) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    *loc = low;
    return false;
}

int main() {


    return 0;
}