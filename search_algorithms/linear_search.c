#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generate_array(int size, int upperLimit) {
    int *data = (int*)malloc(sizeof(int) * size);
    srand(time(0));
    for (int i = 0; i < size; i++)
        data[i] = rand() % upperLimit;
    return data;
}

void print_array(int *data, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
}

void linear_search(int *data, int size, int target) {
    for (int i = 0; i < size; i++)
        if (data[i] == target) {
            printf("\nNumber %d found at index %d\n", target, i);
            return;
        }
    printf("\nNumber %d not found\n", target);
}

int main(void) {
    int size, upperLimit, target;

    printf("Define array size: ");
    scanf("%d", &size);
    printf("Define the upper limit value for each element: ");
    scanf("%d", &upperLimit);
    printf("Enter the target value for the search algorithm: ");
    scanf("%d", &target);

    int *data = generate_array(size, upperLimit);
    print_array(data, size);
    linear_search(data, size, target);

    return 0;
}