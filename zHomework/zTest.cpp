#include<iostream>
using namespace std;

// typedef int ElemType;
typedef struct LNode {
    int val;
    struct LNode* next;
} LNode, * LinkList;

typedef struct SqList {
    int length;
    int data[256];
}SqList;

int main() {
    bool v[2];
    for (int i = 0;i < 2;i++) {
        printf("%d ", v[i]);
    }
    return 0;
}