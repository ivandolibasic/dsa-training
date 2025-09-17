#include <stdio.h>

int M[6][6] = {0}, n = 6, visited[36] = {0};

void dfs(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (M[v][i] == 1 && !visited[i])
            dfs(i, n);
    }
}

int main(void) {
    FILE *f = fopen("adj2.txt", "r");
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            fscanf(f, "%d", &M[i][j]);
    int s;
    printf("Choose the start node: ");
    scanf("%d", &s);
    dfs(s, n);
    return 0;
}