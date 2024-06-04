#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//有序表删除关键字值在s与t(s<t)之间的数据元素。注意健壮性。
bool DelStoT(SqList* L, int s, int t) {
    if (L->length == 0 || s >= t) {
        return false;
    }

    int startLoc, endLocp;
    // for (int i = 0;i < L->length;i++) {

    //     if (L->data[i] >= s) {// 这是跳出循环的条件，可以简写到for循环判断里面。
    //         startLoc = i;
    //         break;
    //     }
    // }
    //
    // for (int i = startLoc;i < L->length;i++) {

    //     if (L->data[i] > t) {
    //         endLocp = i - 1;
    //         break;
    //     }
    // }

    for (startLoc = 0;startLoc < L->length && L->data[startLoc] < s;startLoc++);
    for (endLocp = startLoc + 1;endLocp < L->length && L->data[endLocp] <= t;endLocp++);



    for (int i = 0;i < L->length - 1 - endLocp;i++) { // endLocp+1 ~ n-1
        L->data[startLoc + i] = L->data[endLocp + 1 + i];
    }
    for (;endLocp < L->length;startLoc++, endLocp++) {
        L->data[startLoc] = L->data[endLocp];
    }

    L->length = startLoc;
    return true;
}



int main() {
    SqList L; //在测试的时候，用值变量而不用指针变量，原因是值变量好赋值。
    L.length = 6;

    int testSqL[6] = { 2,4,6,8,10,12 };
    for (int i = 0;i < L.length;i++) {
        L.data[i] = testSqL[i];
    }

    if (DelStoT(&L, 10, 10)) {
        for (int i = 0;i < L.length;i++) {
            printf("%d ", L.data[i]);
        }
        printf("delete successfully!");
    }

    printf("delete !");
    return 0;
}