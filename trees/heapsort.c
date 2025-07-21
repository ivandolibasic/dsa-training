#include <stdio.h>
#include <stdlib.h>

int left(int i) {
    return 2 * i + 1;
}
int right(int i) {
    return 2 * i + 2;
}

void heapify(int data[], int i) {
    int l = left(i), r = right(i), max;

    if ((data[l] > data[i]) && (l < heapSize))
        max = l;
}