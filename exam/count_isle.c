#include <stdio.h>

int M, N;
int A[102][102] = {0};

void erease(int i, int j) {
    if (A[i][j] == 0) return;
    A[i][j] = 0;
    erease(i - 1, j);
    erease(i + 1, j);
    erease(i, j - 1);
    erease(i, j + 1);
}

int main() {
    int i, j, isleCounter = 0;
    scanf("%d%d", &M, &N);
    for (i = 1; i <= M; i++)
        for (j = 1; j <= N; j++)
            scanf("%1d", &A[i][j]);
    for (i = 1; i <= M; i++)
        for (j = 1; j <= N; j++)
            if (A[i][j] == 1) {
                isleCounter++;
                erease(i, j);
            }
    printf("%d", isleCounter);
}