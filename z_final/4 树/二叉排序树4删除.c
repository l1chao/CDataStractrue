//删除没有代码要求，掌握所有情况即可。
/*
1. 叶子节点删除
2. 只有左子树的节点的删除
3. 只有右子树的节点的删除
4. 同时有左子树和右子树的节点的删除（需要用到中序前驱节点、后继节点的判定）
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;

