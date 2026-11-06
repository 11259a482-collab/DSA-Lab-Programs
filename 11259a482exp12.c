Experiment 12:-Implement Graph Search Algorithms (BFS & DFS)
Aim:-To write a C program to represent a graph using an adjacency matrix and
traverse it using Breadth-First Search (BFS) and Depth-First Search (DFS).
Algorithm
1. Read the number of vertices and edges, and construct the adjacency matrix
representing the graph (mark adj[u][v] = adj[v][u] = 1 for each edge, since
the graph is undirected).
2. BFS: mark the starting vertex as visited and insert it into a queue; while
the queue is not empty, remove a vertex, print it, and insert all its unvisited
adjacent vertices into the queue, marking them as visited.
3. DFS: mark the starting vertex as visited and print it; recursively visit each
unvisited adjacent vertex in the same manner.
4. Display the sequence of vertices visited by BFS and by DFS starting from
the given vertex.
Program:
#include <stdio.h>
#define MAX 20
int adj[MAX][MAX];
int visited[MAX];
int n; /* number of vertices */
void bfs(int start) {
 int queue[MAX], front = 0, rear = 0;
 int visitedLocal[MAX] = {0};
 visitedLocal[start] = 1;
 queue[rear++] = start;
 printf("BFS traversal: ");
 while (front < rear) {
 int current = queue[front++];
 printf("%d ", current);
 for (int i = 0; i < n; i++) {
if (adj[current][i] == 1 && !visitedLocal[i]) {
 visitedLocal[i] = 1;
 queue[rear++] = i;
 }
 }
 }
 printf("\n");
}
void dfsUtil(int vertex) {
 visited[vertex] = 1;
 printf("%d ", vertex);
 for (int i = 0; i < n; i++) {
 if (adj[vertex][i] == 1 && !visited[i])
 dfsUtil(i);
 }
}
void dfs(int start) {
 for (int i = 0; i < n; i++)
 visited[i] = 0;
 printf("DFS traversal: ");
 dfsUtil(start);
 printf("\n");
}
int main() {
 int edges, u, v, start;
 printf("Enter number of vertices: ");
 scanf("%d", &n);
 printf("Enter number of edges: ");
 scanf("%d", &edges);
 printf("Enter edges (u v), vertices numbered 0 to %d:\n", n - 1);
 for (int i = 0; i < edges; i++) {
 scanf("%d %d", &u, &v);
 adj[u][v] = 1;
 adj[v][u] = 1; /* undirected graph */
 }
printf("Enter starting vertex: ");
 scanf("%d", &start);
 bfs(start);
 dfs(start);
 return 0;
}
