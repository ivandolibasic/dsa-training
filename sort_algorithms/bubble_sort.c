#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generate_array(int size, int upperLimit) {
    int *data = (int*)malloc(sizeof(int) * size);
    if (data == NULL) {
        print("Memory allocation failed\n");
        return NULL;
    }
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

void bubble_sort(int *data, int size) {
    for (int i = 0; i < size - 1; i++) 
        for (int j = 0; j < size - 1 - i; j++)
            if (data[j] > data[j + 1])
                swap(&data[j], &data[j + 1]);
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
    bubble_sort(data, size);
    print_array(data, size);

    return 0;
}