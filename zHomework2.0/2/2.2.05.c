#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//删除顺序表内关键字值在s到t(s<t)之间的所有元素。注意健壮性。

//法1。无序数组删元素，尾填法。效率很高，但会打乱元素顺序。
// bool DelStoT(SqList* L, int s, int t) {
//     if (s >= t || L->length == 0) {
//         return false;
//     }

//     for (int i = 0;i < L->length;) {
//         if (L->data[i] >= s && L->data[i] <= t) {
//             L->data[i] = L->data[L->length - 1];
//             L->length--;
//         }
//         else {
//             i++;
//         }
//     }
//     return true;
// }


//法2。顺填法。法1用尾元素填充；法2发现元素移动规律，按照顺序填充。发现移动的规律很重要。
bool DelStoT(SqList* L, int s, int t) {
    if (L->length == 0 || s >= t) {
        return false;
    }

    int num = 0;
    for (int i = 0;i < L->length;i++) {
        if (L->data[i] >= s && L->data[i] <= t) {
            num++;
        }
        else {
            L->data[i - num] = L->data[i];
        }
    }

    L->length -= num;
    return true;
}

int main() {
    SqList L;
    L.length = 6;

    int testSqL[6] = { 42,33,12,66,43,2 };
    for (int i = 0;i < L.length;i++) {
        L.data[i] = testSqL[i];
    }

    DelStoT(&L, 0, 41);

    for (int i = 0;i < L.length;i++) {
        printf("%d ", L.data[i]);
    }
}