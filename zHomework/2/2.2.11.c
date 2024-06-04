#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;


//本质思路是：中大右和中小左肯定不是中位数，所以可以删除。删除前后中位数不变的前提，是每次删除的元素个数一样，因为这样可以做到整个排序的状况下是头尾减少了相同元素的。因此需要分奇偶讨论。
int FindMid(int a[], int b[], int l) {
    int s1 = 0, d1 = l - 1, m1, s2 = 0, d2 = l - 1, m2;
    for (;s1 != d1 && s2 != d2;) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (a[m1] == b[m2]) {
            return a[m1];
        }

        if ((d1 - s1 + 1) % 2 == 1) {
            if (a[m1] < b[m2]) {
                s1 = m1;
                d2 = m2;
            }
            else {
                d1 = m1;
                s2 = m2;
            }
        }
        else {
            if (a[m1] < b[m2]) {
                s1 = m1 + 1;
                d2 = m2;
            }
            else {
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }

    return a[m1] < b[m2] ? a[m1] : b[m2];
}

//返回两个等长有序数组的中位数（偶数则为中间偏左的元素）
int FindMid(int a[], int b[], int l) {//a、b数组等长度，长度为l
    int s1 = 0, d1 = l - 1, m1, s2 = 0, d2 = l - 1, m2;
    for (;s1 != d1;) {
        if (a[m1] == b[m2]) {
            return a[m1];
        }
        else if (a[m1] < b[m2]) {
            if ((d1 - s1 + 1) % 2 == 1) {
                s1 = m1;
                d2 = m2;
            }
            else {
                s1 = m1 + 1;
                d2 = m2;
            }
            m1 = (s1 + d1) / 2;
            m2 = (s2 + d2) / 2;
        }
        else {
            if ((d1 - s1 + 1) % 2 == 1) {
                s2 = m2;
                d1 = m1;
            }
            else {
                s1 = m1 + 1;
                d2 = m2;
            }
            m1 = (s1 + d1) / 2;
            m2 = (s2 + d2) / 2;
        }
    }
    return a[s1] < b[s2] ? a[s1] : b[s2];
}
int main() {
    return 0;
}