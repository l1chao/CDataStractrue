#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack {
    char data[256];
    int p;
}stack;

stack* NewStack() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->p = 0;
    return s;
}

bool IsStackEmpty(stack* s) {
    if (s->p == 0) return true;
    return false;
}

// bool IsStackFull(){}

void Push(stack* s, char e) {
    s->data[s->p] = e;
    s->p++;
}
int Pop(stack* s) {
    if (IsStackEmpty(s)) return '\0';
    s->p--;
    return s->data[s->p];
}


int main() {

}