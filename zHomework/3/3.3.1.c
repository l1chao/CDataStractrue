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

//编写算法实现三种括号的配对匹配检查。
bool check(char a[]) {
    int p = 0;
    stack* s = NewStack();
    int temp;
    while (a[p] != '\0') {
        switch (a[p]) {
        case '(': Push(s, '(');break;
        case '[': Push(s, '[');break;
        case '{': Push(s, '{');break;
        case ')': {
            temp = Pop(s);
            if (temp != '(') return false;
            break;
        }
        case ']': {
            temp = Pop(s);
            if (temp != '[') return false;
            break;
        }
        case '}': {
            temp = Pop(s);
            if (temp != '{') return false;
            break;
        }
        }
        p++;
    }

    if (IsStackEmpty(s)) return true;
    return false;
}
int main() {
    char test[7] = { ']','[','{','(',')','}','\0' };
    printf("%d", check(test));

    return 0;
}