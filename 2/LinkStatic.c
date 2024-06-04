#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 10

// struct Node {
//     int data;
//     int next;
// };

typedef struct Node {
    int data;
    int next;
} SLinkList[MaxSize];

int main() {
    // struct Node a[10];
    SLinkList b;
    printf("%d", sizeof(b));
    return 0;
}