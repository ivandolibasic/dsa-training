#include <stdio.h>
#include <stdbool.h>

bool find_subarray(int *vector1, int *vector2, int size1, int size2) {
    /*If vector1 has e.g. 3 elements, and vector2 has 6, 
    the last real position for the start of the subarray 
    is 6 - 3 = 3*/
    for (int i = 0; i <= size2 - size1; i++) {
        if (vector1[0] == vector2[i]) {
            bool found = true;
            for (int j = 1; j < size1; j++) {
                if (vector1[j] != vector2[i + j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    int vector1[] = {20, 30, 40},
        vector2[] = {10, 20, 30, 40, 50},
        size1 = sizeof(vector1) / sizeof(int),
        size2 = sizeof(vector2) / sizeof(int);
    if (find_subarray(vector1, vector2, size1, size2))
        printf("Vector 1 exists within vector 2.");
    else
        printf("Vector 1 doesn't exist within vector 2.");
    return 0;
}