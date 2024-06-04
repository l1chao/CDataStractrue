//利用BFS算法来实现最短路径求解
//算法核心实际上还是对于整个图进行一次广度优先遍历，在此基础上，该算法当然可以看做只是修挂了visit()部分函数的结果。修改的内容本质上是添加了一个类似于双亲节点的东西，这里用数组实现，即核心数组记录了该节点的上一个节点应该是哪一个；这样根节点就是开始遍历的那个节点。
//为了便于查询每个节点和原始节点的距离，需要另外一个数组来记录。实际上如果压缩内存可以不用这个新数组，只需要遍历一次前面所说的核心数组即可。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10 //暂时这样表示图里面有多少个节点
#define MAX_INT_SIZE 10000
int d[SIZE];
int path[SIZE];

void BFS_MIN_Distance(Graph G, int u) {//G图，v开始的顶点。
    for (int i = 0; i < G.vexnum; i++) {
        d[i] = MAX_INT_SIZE;//MAX_INT_SIZE表示最大的int长度。
        path[i] = -1;
    }

    d[u] = 0;//到本身的距离为0
    //不需要path。
    visited[u] = true;
    Enqueue(Q, u);

    for (!IsEmpty(Q)) {
        DeQueue(Q, u);
        for (int w = FirstNeighbor(Q, u); w >= 0; w = NextNeighbor(Q, u, w)) {
            if (!visited(w)) {
                //visit(w)
                d[w] = d[u] + 1;
                path[w] = u;

                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

int main() {


    return 0;
}