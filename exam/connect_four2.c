#include <stdio.h>

int main(void) {
    int M[6][7];
    
    FILE *f = fopen("connect_four2.txt", "r");
    if (!f) return 1;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++)
            fscanf(f, "%d", &M[i][j]);
    fclose(f);

    int winner = 0;
    char how = '0';

    for (int i = 0; i < 6 && !winner; i++)
        for (int j = 0; j <= 7 - 4 && !winner; j++) {
            int x = M[i][j];
            if (x != 0 && M[i][j + 1] == x && M[i][j + 2] == x && M[i][j + 3] == x) { 
                winner = x; how = 'H'; 
            }
        }

    for (int i = 0; i <= 6 - 4 && !winner; i++)
        for (int j = 0; j < 7 && !winner; j++) {
            int x = M[i][j];
            if (x != 0 && M[i + 1][j] == x && M[i + 2][j] == x && M[i + 3][j] == x) {
                winner = x; how = 'V';
            }
        }

    for (int i = 0; i <= 6 - 4 && !winner; i++)
        for (int j = 0; j <= 7 - 4 && !winner; j++) {
            int x = M[i][j];
            if (x != 0 && M[i + 1][j + 1] == x && M[i + 2][j + 2] == x && M[i + 3][j + 3] == x) {
                winner = x; how = 'D';
            }
        }

    for (int i = 3; i < 6 && !winner; i++)
        for (int j = 0; j <= 7 - 4 && !winner; j++) {
            int x = M[i][j];
            if (x != 0 && M[i - 1][j + 1] == x && M[i - 2][j + 2] == x && M[i - 3][j + 3] == x) {
                winner = x; how = 'D';
            }
        }

    printf("%d%c", winner, how);

    return 0;
}