#include <stdio.h>

int arr[] = {5, 2, 4, 6, 1, 3}, size = sizeof(arr) / sizeof(int);

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void insertion_sort(int *arr, int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    print_array(arr, size);
    printf("\n");
    insertion_sort(arr, size);
    print_array(arr, size);
    return 0;
}