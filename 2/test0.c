#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct List {
    int length;
    int data[256];
}List;

//删除值在[s,t]范围内的元素
void Delete_s_to_t(List* L, int s, int t) {
    int slow = 0, quick = 0;
    for (;slow < L->length && L->data[slow] < s; slow++) {}
    for (quick = slow;quick < L->length && L->data[quick] <= t;quick++)

        if (slow == quick) return;

    for (;quick < L->length;quick++, slow++) {
        L->data[slow] = L->data[quick];
    }
    L->length = slow;
}
int main() {

}
