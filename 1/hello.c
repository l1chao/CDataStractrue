#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct SqList {
    int* data[100];
    int length;
} SqList;
void AA(int* a) {
    printf("%d", a[0]);
}

int main() {
    SqList new = { .length = 0 };
    printf("%d", new.data[0]);
    return 0;
}