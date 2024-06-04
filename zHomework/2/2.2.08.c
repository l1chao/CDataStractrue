#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;

void specialReverse(SqList* L, int m, int n) {
    Reverse(L, 0, m - 1);
    Reverse(L, m, m + n - 1);
    Reverse(L, 0, m + n - 1);
}

//mid非常规：mid = (end - start + 1)/2 + start( == length / 2 + start)，此时终点为奇中和偶中后。
//mid常规：mid = (start + end) / 2，此时终点为奇中和偶中前
//上面记忆方法：偶数从中间左到中间右，需要加1。
void Reverse(SqList* L, int start, int  end) {
    ElemType temp;
    for (int i = 0;i < (end - start + 1) / 2 + start;i++) {
        temp = L->data[i];
        L->data[i] = L->data[start + end - i];
        L->data[start + end - i] = temp;
    }
}
int main() {


    return 0;
}