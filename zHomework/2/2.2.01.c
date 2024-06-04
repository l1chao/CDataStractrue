#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int* data[100];
    int length;
} SqList;

bool Del_Min(SqList L, int* e) {
    //扫描整个顺序表，并用变量min记录其中遇到的最小值的下标，遍历结束后用最后一个元素填充这个下标位置。
    if (L.length == 0) {
        printf("List is empty!");
        return false;
    }

    //关键点就是要用两个变量，一个变量记录最小值，一个变量记录最小值的地址。
    int min = L.data[0];
    int location = 0;
    for (int i = 1; i < L.length; i++) {
        if (L.data[i] < min) {
            min = L.data[i];
            location = i;
        }
    }

    L.data[location] = L.data[L.length - 1];
    L.length--;

    return true;
}

bool Del_Min(SqList* L, int* e) {
    if (L->length == 0) {
        return false;
    }

    int min = L->data[0];
    int loc = 0;
    for (int i = 1;i < L->length;i++) {
        if (L->data[i] < min) {
            min = L->data[i];
            loc = i;
        }
    }
    L->data[loc] = L->data[L->length - 1];
    L->length--;
    return true;
}
int main() {


    return 0;
}