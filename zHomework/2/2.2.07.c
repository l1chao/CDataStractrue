#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;

//和链表不同的是：随机访问的一大特性就是有全局的信息。
//为什么考试代码里面有data[i++]的表示？因为太省时间了。必须学会用这种方法来减少单纯的代码书写量。
SqList* Merge(SqList* a, SqList* b) {
    int pa, pb;
    SqList* newList = (SqList*)malloc(sizeof(SqList));
    newList->length = 0;

    for (;pa < a->length && pb < b->length;) {
        if (a->data[pa] <= b->data[pb]) {
            newList->data[newList->length] = a->data[pa];//遍历整个链表，指针指向的元素可以直接被选走，而length指向的位置可以直接插入。
            newList->length++;
            pa++;
        }
        else {
            newList->data[newList->length] = b->data[pa];
            newList->length++;
            pb++;
        }
    }


    if (pa == a->length) {
        for (;pb < b->length;) {
            newList->data[newList->length] = b->data[pb];
            newList->length++;
            pb++;
        }
    }
    else {
        for (;pa < a->length;) {
            newList->data[newList->length] = a->data[pa];
            newList->length++;
            pa++;
        }
    }

    return newList;
}

//合并两个有序顺序表
SqList* Merger(SqList* a, SqList* b) {
    SqList new = { .length = 0 };

    int pa, pb;
    for (pa = pb = 0; pa < a->length && pb < b->length;) {
        if (a->data[pa] <= b->data[pb]) {
            new.data[new.length] = a->data[pa];
            pa++;
        }
        else {
            new.data[new.length] = b->data[pb];
            pb++;
        }
        new.length++;
    }

    if (pa == a->length) {
        for (;pb < b->length;pb++, new.length++) {
            new.data[new.length] = b->data[pb];
        }
    }
    else {
        for (;pa < a->length;pa++, new.length++) {
            new.data[new.length] = a->data[pa];
        }
    }

    return &new;
}

int main() {

    return 0;
}