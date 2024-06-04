#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//递增数组，最快查找，查值x，找到与后继元素交换；找不到则插入x
bool FindXOrInsert(SqList* l, int x) {
    int* loc;
    bool IsFound = FindX(l, x, loc);
    if (IsFound && *loc != l->length - 1) { //实际上这里loc=n-1不需要处理，所以这里一个&&就能够解决问题。
        int temp = l->data[*loc];
        l->data[*loc] = l->data[(*loc) + 1];
        l->data[(*loc) + 1] = temp;
    }
    if (!IsFound) {//loc是下标不是基数。
        for (int i = l->length - 1;i >= *loc;i--) {
            l->data[i + 1] = l->data[i];
        }
        l->data[*loc] = x;
        l->length++;
    }
    return true;
}

//找到x返回下标；找不到x返回x应该插入的地方。
bool FindX(SqList* l, int x, int* loc) {
    int head = 0, tail = l->length - 1;
    int  mid = (head + tail) / 2;
    while (head <= tail) {
        if (l->data[mid] == x) {
            *loc = mid;
            return true;
        }
        else if (l->data[mid] < x) {
            head = mid + 1;
        }
        else {
            tail = mid - 1;
        }
    }
    *loc = head;
    return false;
}

int main() {
    SqList l;
    l.length = 0;

    printf("%d\n", l.data[0]);
    printf("%d\n", l.length);
}