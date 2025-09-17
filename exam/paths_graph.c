#include <stdio.h>

#define NMAX 100

int S[100][100], res[NMAX][NMAX], tmp[NMAX][NMAX], N;

void multiply(int A[NMAX][NMAX], int B[NMAX][NMAX], int C[NMAX][NMAX]) {
    int i, j, k;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void power(int M[NMAX][NMAX], int exp, int result[NMAX][NMAX]) {
    int i, j, base[NMAX][NMAX];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            result[i][j] = (i == j);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            base[i][j] = M[i][j];
    while (exp > 0) {
        if (exp % 2 == 1) {
            multiply(result, base, tmp);
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    result[i][j] = tmp[i][j];
        }
        multiply(base, base, tmp);
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                base[i][j] = tmp[i][j];
        exp /= 2;
    }
}

int main() {
    int /*N,*/ U, V, K, i, j; // U -> V of length K
    FILE *f = fopen("paths_graph.txt", "r");
    fscanf(f, "%d", &N); // number of vertices
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) fscanf(f, "%d", &S[i][j]);
    fscanf(f, "%d%d%d", &U, &V, &K);
    U--; V--;
    power(S, K, res);
    printf("%d", res[U][V]);
    return 0;
}