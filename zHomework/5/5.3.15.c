// 根据满二叉树的前序序列写出其后序序列

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//满二叉树是整齐的，整齐的就会有整齐的思路。面对整齐的、规律的问题，至少应该尝试一下，因为解决它们的过程中，一定会比普通问题更加整齐（更加整齐往往意味着更好处理和便于讨论）

// void PostOrder(int pre[], int l1, int h1, int post[], int l2, int h2) {
//     if (l1 <= h1) {
//         post[h2] = pre[l1];
//         PostOrder(pre, l1 + 1, l1 + (h1 - l1) / 2, post, l2, l2 + (h1 - l1) / 2 - 1);
//         PostOrder(pre, h1 - (h1 - l1) / 2 + 1, h1, post, h2 - (h1 - l1) / 2, h2 - 1);
//     }
// }

void PostOrder(int pre[], int l1, int h1, int post[], int l2, int h2) {
    if (l1 <= h1) {
        post[h2] = pre[l1];
        int half = (h1 - l1) / 2;
        PostOrder(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
        PostOrder(pre, h1 - half + 1, h1, post, h2 - half, h2 - 1);
    }
}