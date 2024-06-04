#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
// #include "3.3.1.c"
#define MaxSize 256

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
}Node, * Tree;

typedef struct Stack {
    Node* data[256];
    int p;
}Stack;

Stack* NewStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->p = 0;
    return s;
}
void Push(Stack* s, Node* n) {
    if (s->p == MaxSize)return;

    s->data[s->p] = n;
    s->p++;
}

void Pop(Stack* s, Node* n) {
    if (s->p == 0) return;

    s->p--;
    n = s->data[s->p];
}

bool IsStackEmpty(Stack* s) {
    return s->p == 0;
}

// 二叉树第一节，中序遍历的非递归算法。
//之前的思路错了，因为不能够只将节点的值给入栈，还是需要将节点本身入栈，这样才能够调用兄弟节点。
void InOrder2(Tree t) {
    Stack* s = NewStack();
    Node* p = t;
    while (p || !IsStackEmpty(s)) {
        if (p) {
            Push(s, p);
            p = p->left;
        }
        else {
            Pop(s, p);
            p = p->right;
        }
    }
}

//二叉树第一节，前序遍历的非递归算法
void PreOrder2(Tree t) {
    Stack* s = NewStack();
    Node* p = t;
    while (p || !IsStackEmpty(s)) {
        if (p) {
            Push(s, p);
            printf("%d", p->val);
            p = p->left;
        }
        else {
            Pop(s, p);
            p = p->right;
        }
    }
}

int main() {


    return 0;
}