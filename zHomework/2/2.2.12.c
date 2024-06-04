#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;

//原理：假设主元素x存在，最坏情况下有l+1个x和l个非x，减去等量个x和非x，剩下的x和非x里面，x仍然为主元素。
//所以，以a[0]为第一个元素，count初始化为1，count一旦为0就更换val和count重新初始化为1，因为
int find(int a[], int n) {
    //有主元素，则输出主元素值；无则输出-1。
    int count, val = 0;
    val = a[0];
    count = 1;
    for (int i = 1; i < n;i++) {
        if (a[i] == val) {
            count++;
        }
        else if (count > 0) {
            count--;
        }
        else {//关键是要处理好更新时间，使得其更新满足同时减去一对元素（x和非x），这样余下数列仍然满足x是主元素。
            val = a[i];
            count = 1;
        }
    }

    if (count > 0) {
        count = 0;
        for (int i = count = 0;i < n;i++) {
            if (a[i] == val) {
                count++;
            }
        }
    }

    if (count > n / 2) return val;
    else return -1;
}

int find(int a[], int n) {
    int val = a[0], count = 1;
    for (int i = 1;i < n;i++) {
        if (a[i] == val) {
            count++;
        }
        else if (count > 0) {
            count--;
        }
        else {
            val = a[i];
            count = 1;
        }
    }

    if (count > 0) {
        for (int i = count = 0;i < n;i++) {
            if (a[i] == val) {
                count++;
            }
        }
    }
    if (count > n / 2) return val;
    return -1;
}

int main() {
    return 0;
}