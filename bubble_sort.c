#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generate_array(int length, int upperLimit) {
    int *payload = (int*)malloc(sizeof(int) * length);
    if (payload == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    srand(time(0));
    for (int i = 0; i < length; i++) {
        payload[i] = rand() % upperLimit;
    }
    return payload;
}

void print_array(int *arr, int length) {
    printf("Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap_elements(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int *reverse_array(int *arr, int length) {
    for (int i = 0; i < length / 2; i++)
        swap_elements(arr, i, length - 1 - i);
    return arr;
}

void find_greater_adjacenties(int *arr, int length) {
    int count = 0;
    printf("Elements with greater adjacent element: ");
    for (int i = 1; i < length - 1; i++) {
        if (arr[i - 1] > arr[i] || arr[i + 1] > arr[i]) {
            printf("%d ", arr[i]);
            count++;
        }
    }
    printf("\nCount: %d\n", count);
}

void bubble_sort(int *arr, int length) {
    for (int i = 0; i < length - i; i++) {
        for (j = i + 1; j < length - i; j++) {
            
        }
    }
}

int main() {
    int len, lim;
    printf("Define the size of an array: ");
    scanf("%d", &len);
    printf("Define the upper limit for each element: ");
    scanf("%d", &lim);

    printf("\n");

    int *arr = generate_array(len, lim);
    print_array(arr, len);

    find_greater_adjacenties(arr, len);

    printf("Reversed ");
    print_array(reverse_array(arr, len), len);

    return 0;
}