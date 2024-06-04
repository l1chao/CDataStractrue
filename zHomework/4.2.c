//第4章主要是讲串，串里面的考点只有一个kmp算法。这个算法主要需要理解的点在next数组的求解上。在有了next数组之后，kmp算法代码如下：

typedef struct SString {
    char ch[256];
    int length
}SString;

// typedef int a[56]; 

int Index_KMP(SString S, SString T, int next[]) {
    int i, j;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }

    if (j > T.length) {
        return i - T.length;
    }
    else return 0;
}