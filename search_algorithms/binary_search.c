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

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
    // negative if (a < b)
    // zero if (a == b)
    // positive if (a > b)
}

void binary_search(int *data, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (data[mid] == target) {
            printf("\nNumber %d found at index %d\n", target, mid);
            return mid;
        }
        else if (data[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
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
    qsort(data, size, sizeof(int), compare);
    print_array(data, size);
    binary_search(data, size, target);

    return 0;
}