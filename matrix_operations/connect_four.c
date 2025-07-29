#include <stdio.h>
#include <stdlib.h>

int inputMatrix[6][7] = {
    {0, 0, 0, 0, 0, 2, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 2, 0, 0, 1, 0},
    {0, 1, 2, 1, 0, 1/*0*/, 1},
    {0, 0, 1, 2, 0, 1, 1},
    {2, 1, 1, 2, 2, 2, 2}
};

// https://chatgpt.com/share/688877ce-0400-8000-bb41-1d7445f5a1a6
void print_matrix(int matrix[6][7]) {
    for (int i = 0; i < 6; i++) {
        for(int j = 0; j < 7; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int M[6][7], count1 = 0, count2 = 0, error[7] = {0}, errorCount = 0;

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++) {
            // scanf("%d", &M[i][j]);
            M[i][j] = inputMatrix[i][j];
            if (M[i][j] == 1) count1++;
            else if (M[i][j] == 2) count2++;
        }
    
    if (count1 > count2 + 1 || count2 > count1 + 1)
        printf("N\n");
    
    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 5; i++) {
            if (M[i][j] == 1 || M[i][j] == 2)
                if (M[i + 1][j] == 0 /* && i < 5*/) {
                    error[j] = j + 1;
                    errorCount++;
                }
                else
                    break;
        }
    }

    for (int j = 0; j < 7; j++)
        if (error[j] != 0)
            printf("%d", error[j]);
    // printf("\n%d", errorCount);
        
    // printf("\n\n");
    // print_matrix(M);
    
    return 0;
}