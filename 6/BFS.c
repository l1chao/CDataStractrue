//广度优先遍历
//因为这篇代码里面涉及到的一些数据结构我懒得编写了，所以这篇代码有很多报错，但是代码本身思路是对的。
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// #include<stdbool.h>

// #define MAX_VERTEX_NUM  1//数组最大长度。暂时用define来表示
// bool visited[MAX_VERTEX_NUM];

// void BFS(Graph G, int v) {//Graph是图
//     visit(v);
//     visited[v] = true;
//     Enqueue(Q, v);//Q是辅助队列。实际上元素在入队之前就已经被访问了，元素入队在具体的代码实现里面是为了检测其子节点的。
//     while (!IsEmpty(Q)) {
//         DeQueue(Q, v);//出队，并将被出队元素的值赋给v；接下来访问所有v节点的子节点，并将这些子节点的子节点入队
//         for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(Q, v, w)) {//因为邻接矩阵、邻接表都确实能够很好的遍历完所有当前节点的子节点，所以这里范围是完备的。 
//             if (!visited[w]) {
//                 visit(w);
//                 visited[w] = true;
//                 EnQueue(w);
//             }
//         }
//     }
// }

// int main() {


//     return 0;
// }