#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

# define MAX_V 10

typedef struct Graph {
    int vexnum;
}Graph;

bool visited[MAX_V];//标记数组

//层序遍历是先出队，再访问。
void BFS(Graph G, int v) {//先访问再入队。
    visit(v);
    visited[v] = true;
    EnQueue(Q, v);

    while (!IsEmpty(Q)) {
        DeQueue(Q, v);
        for (w = FirstNeighbor(G, v);w >= 0;w = NextNeibghbor(G, v, w)) {
            if (!visited[w]) {
                visit(w);
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

void BFSTraverse(Graph G) {
    int i;
    for (i = 0;i < G.vexnum;i++) {
        visited[i] = false;
        InitQueue(Q);
        for (i = 0;i < G.vexnum;i++) {
            if (!visited[i]) {
                BFS(G, i);
            }
        }
    }
}

int main() {


    return 0;
}