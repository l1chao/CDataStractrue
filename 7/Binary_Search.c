//折半查找。这个算法只对有序数组有效。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int* elem;
    int TableLen;
}SStable;

//当L是升序排列时的处理代码。
int Binary_Search(SStable L, int key) {
    int low, high, mid;
    low = 0;
    high = L.TableLen - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid == key) {
            return mid;
        }
        else if (key < mid) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}
int main() {


    return 0;
}