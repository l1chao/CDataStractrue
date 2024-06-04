//这篇代码主要实现了图的广度优先遍历。目的是1.复习广度优先遍历2.复习队列的使用（包括封装情况下的队列和简易情况下的队列。
#include<iostream>
using namespace std;


struct Stack {
    int data[MAXV];
    int p;//指向下一个可插点
};

Stack* NewStack() {
    Stack S = { p:0 };
    return &S;
}

bool IsEmpty(Stack* S) {
    if (S->p == 0) return true;
    return false;
}

void Push(Stack* S, int item) {
    S->data[S->p++] = item;
}

void Pop(Stack* S, int* u) {
    *u = S->data[--S->p];
}

struct Queue
{
    int* val; //注意C++里面想要动态决定结构体里面的数组，就必须要通过new int[n]的方式实现。
    int front, rear;
    int MaxSize;
};

//链表可以用一次性队列来实现，因为不确定是否是“众星捧月”的极端情况，所以即使是循环队列，也需要留够能够装满n-1个节点的空间，所以干脆就直接使用一次性空间。
Queue* NewQueue(int n) {
    Queue Q = {
        val: new int[n],
        front : -1,//取front虚，rear实
        rear : -1,
        MaxSize : n,
    };
    return &Q;
}

bool IsEmpty(Queue* Q) {
    return Q->rear == Q->front;
}

//为什么不需要判满？因为题目本身输入条件就不存在满的情况。在考场上面尽量还是需要什么写什么，而不应该花更多的时间去保证代码的健壮性。考试状态下的代码书写，本身就没有健壮性的需求。
// bool IsFull(Queue* Q) {
//     if (Q->rear == Q->MaxSize - 1) return true;
//     return false;
// }
void EnQueue(Queue* Q, int u) {
    Q->val[++Q->rear] = u;
}

void DeQueue(Queue* Q, int* u) {
    if (IsEmpty(Q)) {
        *u = -1;
        return;
    }

    *u = Q->val[++Q->front];
}

int GetHead(Queue* Q) {
    if (IsEmpty(Q)) return -1;

    return Q->val[Q->front + 1];
}

//简易队列使用（重在及时性和建议性）


const int MAXV = 1000;

struct Graph
{
    int V, E; // 点总数，边总数。
    char VList[MAXV]; //顶点列表
    int Edge[MAXV][MAXV]; //边
};

void visit(int v) {//如果只传一个v进去，要想访问节点，应该在全局有一个节点相关的表。
    printf("%d visited.", v);
}

int FirstNeighbor(Graph G, int v) {
    for (int i = 0; i < MAXV;i++) {
        if (G.Edge[v][i] != 0) {
            return i;
        }
    }
    return -1;
}

int NextNeighbor(Graph G, int v, int u) {
    for (int i = u + 1;i < MAXV;i++) {
        if (G.Edge[v][i] != 0) {
            return i;
        }
    }
    return -1;
}

//封装后的队列调用——图的遍历
void BFSTraverse(Graph G) {
    bool visited[MAXV];
    for (int i = 0; i < MAXV;i++) {
        visited[i] = false;
    }

    for (int i = 0; i < MAXV;i++) {
        if (!visited[i]) {
            BFS(G, i, visited);
        }
    }
}
void BFS(Graph G, int v, bool visited[]) {//出一个队 添加其子
    int u;
    Queue* Q = NewQueue(G.V);
    visit(v);
    visited[v] = true;
    EnQueue(Q, v);

    while (!IsEmpty(Q)) {
        DeQueue(Q, &u);
        for (v = FirstNeighbor(G, u);v >= 0;v = NextNeighbor(G, u, v))
            if (!visited[v]) {
                visit(v);
                visited[v] = true;
                EnQueue(Q, v);
            }
    }
}

//寻找单源最佳路径。 
//输入：1.保证是一个连通图 2.保证v合法
int* BFSBestRoute(Graph G, int v) {
    bool visited[MAXV];
    for (int i = 0;i < MAXV;i++) {
        visited[i] = false;
    }

    int d[MAXV] = { -1 };
    int Q[MAXV];
    int front = -1, rear = -1;

    Q[++rear] = v;
    d[v] = 0;
    while (front < rear) {
        int u = Q[++front];
        visited[u] = true;
        for (int i = FirstNeighbor(G, u);i >= 0;i = NextNeighbor(G, u, i))
            if (!visited[i]) {
                visited[i] = true;
                d[i] = d[u] + 1;
                Q[++rear] = i;
            }
    }

    return d;
}

//判断一个无向图是不是树，是返回true，否则false
bool IsTree(Graph G) {
    bool visited[MAXV];
    for (int i = 0;i < MAXV;i++) {
        visited[i] = false;
    }

    int Vnum, Enum;
    DFS(G, 0, &Vnum, &Enum, visited);

    if (Vnum == G.V && Enum == 2 * (G.E - 1)) return true;
    return false;
}

void DFS(Graph G, int v, int* Vnum, int* Enum, bool visited[]) {
    visited[v] = true;
    *Vnum++;

    for (int i = FirstNeighbor(G, v); i >= 0;i = NextNeighbor(G, v, i)) {
        *Enum++;
        if (!visited[i])
            DFS(G, i, Vnum, Enum, visited);
    }
}


//深度优先图的非递归遍历(伪代码)
void BFS_no_RC(Graph G, int v) {
    bool visited[MAXV];
    for (int i = 0; i < MAXV; i++) {
        visited[i] = false;
    }

    Stack* S = NewStack();
    Push(S, v);
    while (!IsEmpty(S)) {
        int k = 0;
        Pop(S, &k);
        visit(k);
        for (int w = FirstNeighbor(G, k);w >= 0;k = NextNeighbor(G, k, w)) {
            if (visited[w]) {
                Push(S, w);
                visit(w);
            }
        }
    }
}

//分别用宽搜和深搜实现两点连通性的确认。
//先写伪代码，再来补充细节。
bool BFSDetect(Graph G, int i, int j) {
    bool visited[MAXV];
    for (int i = 0;i < MAXV;i++) {
        visited[i] = false;
    }

    Queue* Q = NewQueue(MAXV);
    EnQueue(Q, i);
    while (!IsEmpty(Q)) {
        int k;
        DeQueue(Q, &k);
        visited[k] = true;
        if (k == j) {
            return true;
        }
        for (int w = FirstNeighbor(G, k); w >= 0; w = NextNeighbor(G, k, w)) {
            if (!visited[w]) {
                EnQueue(Q, w);
            }
        }
    }
    return false;
}

//利用深搜实现连通性探测
// bool DFSDetect(Graph G, int i, int j) {
//     bool visited[MAXV]; //init:false
//     bool flag = false;
//     DFSD(G, visited, &flag, 0, j);
// }

// void DFSD(Graph G, bool visited[], bool* flag, int i, int j) {
//     if (i == j) {
//         *flag = true;
//         return;
//     }
//     visited[i] = true;

//     for (int w = FirstNeighbor(G, i);w >= 0;w = NextNeighbor(G, i, w)) {
//         if (!visited[w] && !flag) {
//             DFSD(G, visited, flag, w, j);
//         }
//     }
// }

bool DFSDetect(Graph G, int i, int j) {//这个函数用来给递归程序提供环境的。
    bool can_reach = false;
    bool visited[MAXV];

    DFSR(G, i, j, visited, &can_reach);
    return can_reach;
}

void DFSR(Graph G, int i, int j, bool visited[], bool* flag) {
    if (i == j) {
        *flag = true;
        return;
    }

    visited[i];
    for (int w = FirstNeighbor(G, i);w >= 0; w = NextNeighbor(G, i, w)) {
        if (!visited[w] && !(*flag)) {
            DFSR(G, w, j, visited, flag);
        }
    }
}

//广搜实现路径探测
bool BFSDetect(Graph G, int i, int j) {
    bool visited[MAXV];
    bool can_reach = false;

    BFSD(G, i, j, &can_reach, visited);
    return can_reach;
}

void BFSD(Graph G, int i, int j, bool* flag, bool visited[]) {
    Queue* Q = NewQueue(G.V);
    EnQueue(Q, i);

    while (!IsEmpty(Q)) {
        int v;
        DeQueue(Q, &v);
        visited[v] = true;
        if (v == j) {
            *flag = true;
            return;
        }
        for (int w = FirstNeighbor(G, v);w >= 0;w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                EnQueue(Q, w);
            }
        }
    }
}

int main() {

    return 0;
}