#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSTRLEN 255

typedef struct SString {
    int length;
    char ch[255];
}SString;
int Index_KMP(SString S, SString T, int next[]) {
    // printf("%d", next[5]);
    int i, j = 1;

    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }

    if (j > T.length) {
        return i - T.length;
    }

    else
        return 0;
}

int main() {
    int next[6] = { 0,0,0,0,0,4 };
    char S_str[] = " aaaacbaaaabc";
    char T_str[] = " aaaab";
    SString S = { .ch = S_str, .length = strlen(S_str) - 1 };
    SString T = { .ch = T_str, .length = strlen(T_str) - 1 };
    printf("%d", Index_KMP(S, T, next));

    return 0;
}