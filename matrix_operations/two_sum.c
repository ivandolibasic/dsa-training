#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *create_array(int size, int limit) {
    srand(time(0));
    int *array = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        array[i] = rand() % limit;
    return array;
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void find_two_sum(int target, int size, int *array) {
    int count = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (target == (array[i] + array[j])) {
                printf("Pair at positions: %d and %d\n", i, j);
                count++;
            }
    if (count == 0)
        printf("There are no such numbers.");
}

int main(void) {
    int size, limit, target;
    printf("Enter the size of an array: ");
    scanf("%d", &size);
    printf("Enter the upper limit for each element of an array: ");
    scanf("%d", &limit);

    int *array = create_array(size, limit);
    print_array(array, size);

    printf("\nEnter the target value: ");
    scanf("%d", &target);

    find_two_sum(target, size, array);

    return 0;
}