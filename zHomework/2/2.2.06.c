#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;

bool del_same(SqList* L) {
    if (L->length == 0 || L->length == 1) {
        return false;
    }

    int head = 0, p = 0;
    for (;p < L->length; p++) {//总要有记录重复段的开头，这样才能够直到从哪里开始重复的。从普遍情况开始写代码，然后讨论特殊情况。这里的特殊情况就是下一个如果就是不重复的如何解决——实际上和代码一样，所以不需修改。
        if (L->data[p] != L->data[head]) {//head记录头，一样就跳过，不一样就在head的下一个插入。
            head++;
            L->data[head] = L->data[p];
        }
    }
    L->length = head + 1;
    return true;
}

bool Del_same(SqList* L) {
    if (L->length == 0) return false;

    int slow = 0;
    for (int i = 1;i < L->length;i++) {
        if (L->data[i] != L->data[slow]) {
            slow++;
            L->data[slow] = L->data[i];
        }
    }
    L->length = slow + 1;
    return true;
}

int main() {


    return 0;
}