//顺序存储实现队列
//这里采用的是rear代表下一个可插元素位置。
//实现队列的主要问题是数组里面的指针问题。最常用的指针方案是front指头，rear指尾+1元素。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 10

typedef struct {
    int data[256];
    int front, rear;
}SqQueue;

void InitQueue(SqQueue* Q) {
    Q->front = Q->rear = 0;
}

bool IsQueueEmpty(SqQueue* Q) {
    if (Q->rear == Q->front) {
        return true;
    }

    return false;
}

bool IsQueueFull(SqQueue* Q) {
    if ((Q->rear + 1) % MaxSize == Q->front) {//模10，所得数为0到9
        return true;
    }

    return false;
}
bool EnQueue(SqQueue* Q, int val) {
    if (IsQueueFull(Q)) {
        return false;
    }

    Q->data[Q->rear] = val;
    Q->rear = (Q->rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue* Q, int* e) {
    if (IsQueueEmpty(Q)) {
        return false;
    }

    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return true;
}

bool GetHead(SqQueue* Q, int* e) {
    if (IsQueueEmpty(Q)) {
        return false;
    }

    *e = Q->data[Q->front];
    return true;
}

int main() {


    return 0;
}