#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linear_search(int n, int x) {
    int *array = (int*)malloc(sizeof(int) * n), i;

    srand(time(0));

    for (i = 0; i < n; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
        if (x == array[i]) {
            printf("\nNumber %d found at index %d\n", x, n);
            return;
        }
    }

    if (i == n) {
        printf("\nNumber %d not found\n", x);
        return;
    }
}

int main(void) {
    int n, x;
    
    printf("Define the number of elements for an array: ");
    scanf("%d", &n);
    printf("Enter the number you want to search in an array: ");
    scanf("%d", &x);

    linear_search(n, x);

    return 0;
}