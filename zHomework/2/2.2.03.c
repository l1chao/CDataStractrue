#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct SqList {
    ElemType* data[100];
    int length;
} SqList;

// bool DeleteElem(SqList* L, ElemType x) {
//     //由后至前遍历，找到第一个不是x的元素k，并将沿路所有x的元素删除。然后用双指针扫描，i记录末尾元素位置，j往前遍历，每遇到一个x，就将末尾元素填充到x上面，然后i--，直到完成遍历。
//     if (L->length == 0) {
//         return false;
//     }

//     int i, j;
//     for (i = L->length - 1; i >= 0 && L->data[i] == x;i--) {}//结束后i指向第一个不为x的元素下标

//     L->length -= L->length - 1 - i;//删除末尾所有连续的x元素

//     for (j = i - 1;j >= 0;) {
//         if (L->data[j] == x) {
//             L->data[j] = L->data[i];
//             L->length--;
//             i--;
//             j--;
//         }
//         else {
//             j--;
//         }
//     }
//     return true;
// }

//思路是将所有不为x的元素排到头部去。头部用慢指针，遍历用快指针
//顺序表里面的删除，基本上都是用尾填法来实现的，这样能够避免删除元素的时候的大量元素移动。
//把所有需要删除的x全部移动到最后，实现其实是将所有不为x的全部移动到前面去。
void del_x(SqList* L, ElemType x) {
    int i, k;
    for (i = 0; i < L->length; i++) {
        if (L->data[i] != x) {
            L->data[k] = L->data[i];
            k++;//k遇到x会阻塞，直到下一次非x来填充
        }
    }
    L->length = k;//不是k+1,因为在退出循环之前，k有一次自增。
}

void Del_x(SqList* L, ElemType x) {
    int head = 0;
    for (int i = 0;i < L->length;i++) {
        if (L->data[i] != x) {
            L->data[head] = L->data[i];
            head++;
        }
    }
    L->length = head;
}

int main() {


    return 0;
}