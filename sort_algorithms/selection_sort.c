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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *data, int size) {
    int min;
    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++)
            if (data[min] > data[j])
                min = j;
        if (min != i)
            swap(&data[i], &data[min]);
    }
}

int main(void) {
    int size, upperLimit;
    printf("Define array size: ");
    scanf("%d", &size);
    printf("Define the upper limit value for each element: ");
    scanf("%d", &upperLimit);

    int *data = generate_array(size, upperLimit);
    print_array(data, size);
    printf("\n");
    selection_sort(data, size);
    print_array(data, size);

    return 0;
}