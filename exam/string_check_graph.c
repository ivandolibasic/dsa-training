// #include <stdio.h>

// #define MAX 100

// int nodes, edges;
// char adj[MAX][MAX], visited[MAX], labels[6], word[MAX];

// void add_edges(char v, char u) {
//     adj[v][u] = 1;
// }

// int main(void) {
//     FILE *f = fopen("string_check.txt", "r");

//     fscanf(f, "%d", &nodes);
//     printf("%d\n", nodes);

//     for (int i = 0; i < nodes; i++)
//         fscanf(f, " %c", &labels[i]);
    
//     fclose(f);

//     for (int i = 0; i < nodes; i++)
//         printf("%c ", labels[i]);

//     return 0;
// }

#include <stdio.h>
#include <string.h>

int trazi(int cvor, int poz, int N, int G[100][100],
          char znakCvora[100], char S[100], int posjecen[100]) {

    if (znakCvora[cvor] != S[poz]) return poz; // koliko smo stigli

    if (S[poz+1] == '\0') return poz+1; // cijeli string pronađen

    posjecen[cvor] = 1;
    int maxPref = poz+1;

    for (int j = 0; j < N; j++) {
        if (G[cvor][j] && !posjecen[j]) {
            int rez = trazi(j, poz+1, N, G, znakCvora, S, posjecen);
            if (rez == strlen(S)) { // našli cijeli string
                posjecen[cvor] = 0;
                return rez;
            }
            if (rez > maxPref) maxPref = rez;
        }
    }

    posjecen[cvor] = 0;
    return maxPref;
}

int main(void) {
    int N, M, G[100][100] = {0};
    char red[100], S[100], znakCvora[100], cvorZnaka[256];
    int i;

    fgets(red, 100, stdin);
    sscanf(red, "%d", &N);
    for (i = 0; i < N; i++) {
        fgets(red, 100, stdin);
        znakCvora[i] = red[0];
        cvorZnaka[(unsigned char)red[0]] = i;
    }

    fgets(red, 100, stdin);
    sscanf(red, "%d", &M);
    for (i = 0; i < M; i++) {
        fgets(red, 100, stdin);
        G[cvorZnaka[(unsigned char)red[0]]][cvorZnaka[(unsigned char)red[2]]] = 1;
        G[cvorZnaka[(unsigned char)red[2]]][cvorZnaka[(unsigned char)red[0]]] = 1;
    }

    fgets(S, 100, stdin);
    S[strlen(S)-1] = 0; // makni enter5

    int maxPrefiks = 0;
    int found = 0;

    for (i = 0; i < N; i++) {
        if (znakCvora[i] == S[0]) {
            int posjecen[100] = {0};
            int rez = trazi(i, 0, N, G, znakCvora, S, posjecen);
            if (rez == strlen(S)) { // našli string
                found = 1;
                break;
            }
            if (rez > maxPrefiks) maxPrefiks = rez;
        }
    }

    if (found)
        printf("DA %d\n", (int)strlen(S));
    else
        printf("NE %d\n", maxPrefiks);

    return 0;
}