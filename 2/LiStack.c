//链栈
//由于栈的只在一端进行操作的特性，如果将操作限定在头结点一端，那么就是单链表的复习了。
//下面完成链栈的所有基础功能。注意，以不带头结点的链表实现之。

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
}LinkNode, * LiStack;


bool InitStack(LiStack S) {
    S->next = NULL;
}

//这里要实现链栈的销毁，实际上就是实现链表的销毁，链表的销毁需要遍历节点并删除。
bool DestroyStack(LiStack S) {
    LinkNode* q;
    while (S != NULL) {
        q = S;
        S = S->next;
        free(q);//释放的是q所指向的内存，q本身作为变量不会被“free”掉，即循环里面q=S不会出错。
    }
}

bool IsStackEmpty(LiStack S) {
    return S == NULL;
}

//因为链栈上不封顶，所以没有必要检测是否栈满。
// bool IsStackFull(LiStack S){}

//链表实现栈，push是通过头插法实现的，头插法即使没有头结点，处理逻辑也很简单。
bool Push(LiStack S, int val) {
    LiStack NewNode = (LinkNode*)malloc(sizeof(LinkNode));
    NewNode->data = val;
    NewNode->next = S;
    S = NewNode;
    return true;
}

bool Pop(LiStack S, int* e) {
    if (IsStackEmpty(S)) {
        return false;
    }

    LinkNode* q = S;
    S = S->next;
    free(q);
    return true;
}

//获取栈顶元素，返回值应该是一个ElemType，但是如果获取不到，应该返回什么呢？可以这样处理：因为c语言只能够返回一种类型，所以返回类型可以设置为bool，返回值利用指针传输即可。
bool GetTop(LiStack S, int* e) {
    if (S == NULL) {
        return false;
    }

    *e = S->data;
    return true;
}


int main() {

    return 0;
}