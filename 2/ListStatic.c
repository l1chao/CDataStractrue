/*静态分配内存的顺序表相关操作*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 10


typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

void InitList(SqList* L) {
    L->length = 0;
}

//两个基本检查点：位置和个数，有其他再添加，免得浪费时间去思考空洞结论。

//插入一个元素作为第loc个元素。
//检查-移动-插入-更新
bool InsertList(SqList* L, int loc, int data) {
    if (loc < 1 || loc > L->length + 1) {
        return false;
    }
    if (L->length == MaxSize) {
        return false;
    }

    for (int i = L->length; i >= loc; i--) {
        L->data[i] = L->data[i - 1];
    }

    L->data[loc - 1] = data;

    L->length++;

    return true;
}

//删除第loc个元素(loc>=1)
//检查-存储-移动-更新
bool ListDelete(SqList* L, int loc, int* e) {
    if (loc < 1 || loc > L->length) {
        return false;
    }
    if (L->length == 0) {
        return false;
    }

    *e = L->data[loc - 1];

    for (int i = loc - 1; i < L->length - 1;i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;

    return true;
}
//打印顺序表内容
void ListPrint(SqList* L) {
    printf("The length of the list: %d\nAnd data are as follows:\n", L->length);

    for (int i = 0;i < L->length;i++) {
        printf("%d: %d\n", i, L->data[i]);
    }

    return;
}

//根据位置查找值（未检查输入）
int GetIterm(SqList* L, int loc) {
    return L->data[loc - 1];
}

//查找值的位置（未检查输入）
int GetLocation(SqList* L, int val) {
    for (int i = 0; i < L->length;i++) {
        if (L->data[i] == val) {
            return i;
        }
    }
    return -1;
}


int main() {
    SqList L;
    InitList(&L);
    ListInsert(&L, 1, 3);
    ListInsert(&L, 1, 2);
    ListInsert(&L, 1, 1);
    ListPrint(&L);
    int D = -1;
    ListDelete(&L, 1, &D);
    printf("%d", D);
    ListPrint(&L);
    return 0;
}