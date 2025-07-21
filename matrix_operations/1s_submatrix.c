#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int counter = 0,
        A[4][4] = { 
        {1, 0, 1, 1}, 
        {1, 0, 1, 1}, 
        {1, 1, 1, 1}, 
        {1, 1, 0, 0} 
    };
    // https://www.w3schools.com/c/c_arrays_multi.php

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i][j] == 1 && 
                A[i][j + 1] == 1 && 
                A[i + 1][j] == 1 && 
                A[i + 1][j + 1] == 1) {
                counter++;
            }
        }
    }

    printf("%d", counter);

    return 0;
}