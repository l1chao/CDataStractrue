/*动态分配内存的顺序表相关操作*/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define InitSize 10

typedef struct
{
    /* data */
    int* data;
    int MaxSize;
    int length;
} SqList;

void InitList(SqList* L) {
    L->data = (int*)malloc(sizeof(int) * InitSize);
    L->MaxSize = InitSize;
    L->length = 0;
}

int GetElme(SqList* L, int loc) {

    return L->data[loc - 1];
}
int main() {
    SqList L;
    InitList(&L);

    return 0;
}