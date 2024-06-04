#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int Binary_Search(int data[], int n, int key) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (data[mid] == key) return mid;
        else if (data[mid] > key)high = mid - 1;
        else low = mid + 1;
    }

    return -1;//查找失败
}

int main() {


    return 0;
}