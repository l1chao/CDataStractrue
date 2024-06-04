//利用BFS来实现单源最短路径的查找
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

# define MAX_V 10
// # define INFINITE 
typedef struct Graph {
    int vexnum;
}Graph;

int d[MAX_V];
bool visited[MAX_V];
void BFS_MIN_Distance(Graph G, int u) {//u节点为单元
    for (int i = 0;i < G.vexnum;i++) {
        d[i] = INT_MAX;
    }

    visited[u] = true;
    d[u] = 0;
    EnQueue(Q, u);
    while (!IsEmpty(Q)) {
        DeQueue(Q, u);
        for (int w = FirstNeighbor(G, u);w >= 0;w = NextNeighbor(G, u, w)) {
            if (!d[w]) {
                visited[w];
                d[w] = d[u] + 1;
                EnQueue(Q, w);
            }
        }
    }

}