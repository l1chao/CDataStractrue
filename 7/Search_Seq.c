//顺序查找

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int* elem;
    int TableLen;
}SStable;

int Search_Seq(SStable ST, int key) {
    int i;
    for (i = 0; i < ST.TableLen && ST.elem[i] != key; i++);
    return i == ST.TableLen ? -1 : i;
}

int main() {


    return 0;
}