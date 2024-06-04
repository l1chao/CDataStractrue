#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSTRLEN 255

//注意，SString就是长度为256的char数组，因为c里面没有String这种数据结构，所以这里自定义一个。
typedef unsigned char SString[MAXSTRLEN + 1];


//T是模式串，S是待匹配串
int Index(SString S, SString T) {
    int i, j = 0;
    while (i < strlen(S) && j < strlen(T)) {
        if (S[i] == T[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == strlen(T)) {
        return i - j;
    }

    return -1;//表示没有匹配的子串。

}

int main() {
    SString S = "nihaoshaabinihao";
    SString T = "shabi";
    // printf("%s", S);
    printf("%d", Index(S, T));
    return 0;
}