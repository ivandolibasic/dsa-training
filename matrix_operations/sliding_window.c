#include <stdio.h>
#include <stdlib.h>

int arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}, n = sizeof(arr) / sizeof(int), k = 4; // 4, 2, 10, 23 = max window

int max_sum_subarray() {
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i]; // sum of first window

    int window_sum = max_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k]; // slide window, add new, substract old
        if (window_sum > max_sum)
            max_sum = window_sum;
    }
    
    return max_sum;
}

int main() {
    printf("%d", max_sum_subarray(arr, n, k));
    return 0;
}