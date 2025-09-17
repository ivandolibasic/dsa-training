#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX] = {0}, visited[MAX] = {0}, queue[MAX], front = 0, rear = -1;

void add_edge(int v, int u) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void dfs(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (adj[v][i] == 1 && !visited[i])
            dfs(i, n);
}

int main(void) {
    int n, e;
    FILE *f = fopen("nodes_edges.txt", "r");
    fscanf(f, "%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        int u, v;
        fscanf(f, "%d %d", &u, &v);
        add_edge(u, v);
    }

    dfs(4, n);

    return 0;
}