//中序线索化一棵树
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ThreadNode {
    int data;
    struct ThreadNode* lchild, * rchild;
    int ltag, rtag;
}ThreadNode, * ThreadTree;

void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

//
void visit(ThreadNode* T) {
    if (T->lchild == NULL) {
        T->lchild = pre;
        T->ltag = 1;//表示此时左节点是线索节点
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = T;
        pre->rtag = 1;
    }
    pre = T;
}

//创建一个中序线索化数。其实下面的逻辑可以将非线索化的树直接给中序线索化（这将会涉及到节点的改变，主要是ltag等的加入）
ThreadNode* pre = NULL;
void CreateInThread(ThreadTree T) {
    //用于保存当前访问节点的前一个节点。
    if (T != NULL) {
        InThread(T);//此处结束后，pre一定指向中序遍历里面最后一个元素，这个元素必定要么仅有左节点，要么左右节点均无，这两种情况下其右节点都是null的，所以下面两句是自然的。
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

//找到以p为根节点的树被中序遍历第一个访问的点
ThreadNode* FirstNode(ThreadNode* p) {
    while (p->ltag == 0) {//这一步好像没有什么问题，因为叶子结点就是会有p->ltag==1
        p = p->lchild;
    }

    return p;
}

//寻找某节点的下一个中序遍历序列里面的节点
ThreadNode* NextNode(ThreadNode* p) {
    if (p->rtag == 0) {
        return Firstnode(p->rchild);
    }
    else {
        return p->rchild;
    }
}

//利用上面两个函数，能够实现非递归的遍历如下
void InOrder_cheap(ThreadNode* T) {
    for (ThreadNode* p = FirstNode(T);p != NULL; p = NextNode(p)) {
        visit(p);
    }
}

//找到以p为根的处于中序遍历序列最后一个的节点
ThreadNode* LastNode(ThreadNode* p) {
    while (p->rtag == 0) {
        p = p->rchild;
    }
    return p;
}

//前驱只有两种情况：要么是左子树的中序序列末，要么直接是线索。 b
ThreadNode* PreNode(ThreadNode* p) {
    if (p->ltag == 1) {
        return p->lchild;
    }
    else {
        return LastNode(p->lchild);
    }
}

//由上面两个操作能够实现中序二叉树的逆序遍历。
void RevInOrder(ThreadNode* T) {
    for (ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p)) {
        visit(p);
    }
}

int main() {


    return 0;
}