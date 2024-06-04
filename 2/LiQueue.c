//链表实现队列
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LinkNode {
    int data;
    struct LinkNode* next;
}LinkNode;

typedef struct {
    LinkNode* front, * rear;//真容易出错，两个星号*不能少！
}*LinkQueue;

//带头结点初始化
bool InitQueue(LinkQueue Q) {
    Q->front = Q->rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q->front->next = Q->rear->next = NULL;
}

//带头结点判断空队列
bool IsQueueEmpty(LinkQueue Q) {
    //或者判断front.next是不是null
    return Q->front == Q->rear;//注意，这个时候，front和rear都指向头结点。
}

//不带头结点初始化队列
bool InitQueue_noHead(LinkQueue Q) {
    Q->front = Q->rear = NULL;
}

//不带头结点判断空队列
bool IsQueueEmpty_noHead(LinkQueue Q) {
    if (Q->front == Q->rear) {
        return true;
    }

    return false;
}

//带头结点入队
void EnQueue(LinkQueue Q, int data) {
    //思路：利用尾节点作为前驱节点插入新节点，然后再更新尾节点。
    LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
    NewNode->data = data;
    NewNode->next = NULL;
    Q->rear->next = NewNode;
    Q->rear = NewNode;
}

//不带头结点的入队
void EnQueue_noHead(LinkQueue Q, int data) {
    LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
    NewNode->data = data;
    NewNode->next = NULL;

    if (IsQueueEmpty_noHead(Q)) {
        Q->front = Q->rear = NewNode;
    }

    Q->rear->next = NewNode;
    Q->rear = NewNode;
}

//带头结点出队
bool DeQueue(LinkQueue Q, int* e) {
    if (IsQueueEmpty(Q)) {
        return false;
    }

    LinkNode* q = Q->front->next;
    Q->front->next = q->next;
    *e = q->data;

    if (Q->rear == q) {//这里rear指向队尾元素
        Q->rear = Q->front;
    }

    free(q);
    return true;
}

//不带头结点出队
bool DeQueue_noHead(LinkQueue Q, int* e) {
    if (IsQueueEmpty_noHead(Q)) {
        return false;
    }

    LinkQueue* q = Q->front;
    Q->front = Q->front->next;
    *e = Q->front->data;
    free(q);
    return true;
}

int main() {



    return 0;
}