#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define INT_MAX 0x7fffffff
int abs_(int a) {
    return a >= 0 ? a : -a;
}

bool Min_of_Three(int a, int b, int c) {
    if (a <= b && a <= c) return true;
    else return false;
}

//返回所有三元组中的最小距离
int Find(int a[], int b[], int c[], int al, int bl, int cl) {
    int pa = 0, pb = 0, pc = 0;
    int min = INT_MAX;
    int D = 0;
    for (;pa < al && pb < bl && pc < cl;) {
        D = abs_(a[pa] - b[pb]) + abs_(a[pa] - c[pc]) + abs_(b[pb] - c[pc]);
        min = min < D ? min : D;

        if (Min_of_Three(a[pa], b[pb], c[pc])) pa++;
        if (Min_of_Three(b[pb], a[pa], c[pc])) pb++;
        if (Min_of_Three(c[pc], b[pb], a[pa])) pc++;
    }

    return min;
}



int main() {
    return 0;
}