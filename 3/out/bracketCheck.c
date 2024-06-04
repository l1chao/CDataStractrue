//括号匹配。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 50

typedef struct {
    int data[MaxSize];
    int top;
}SqStack;

SqStack* InitStack() {
    SqStack* S = (SqStack*)malloc(sizeof(SqStack));
    S->top = -1;
    return S;
}

bool IsStackEmpty(SqStack* S) {
    return S->top == -1;
}

bool IsStackFull(SqStack* S) {
    return S->top + 1 == MaxSize;
}

//栈操作因为将所有操作固定在了栈顶，所以总体来说要判断的非法操作就很少。一般来说，只需要判断栈满或空即可。
bool Push(SqStack* S, int val) {
    if (IsStackFull(S)) {
        return false;
    }
    S->top++;
    S->data[S->top] = val;
    return true;
}

//出站操作
bool Pop(SqStack* S, char* e) {
    if (S->top == -1) {
        return false;
    }

    *e = S->data[S->top];
    S->top--;
    return true;
}

bool GetTop(SqStack* S, int* e) {
    if (IsStackEmpty(S)) {
        return false;
    }

    *e = S->data[S->top];
    return true;
}

//解决括号匹配问题的方法。注意，这里的问题中，括号不是只需要数量相等就行了，而是需要像代码片段里面那样进行有意义的配对。
//动态地思考：
bool bracketCheck(char str[], int length) {
    SqStack* S = InitStack();

    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        }
        else {
            if (IsStackEmpty(S)) {
                return false;
            }

            char topElem;
            Pop(S, &topElem);

            if (str[i] == ')' && topElem != '(') return false;
            if (str[i] == ']' && topElem != '[') return false;
            if (str[i] == '}' && topElem != '{') return false;
        }
    }

    return IsStackEmpty(S);
}

int main() {
    printf("%d", bracketCheck("(()())(())", 9));
    printf("%d%d", true, false);
    return 0;
}