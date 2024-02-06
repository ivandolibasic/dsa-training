#include <stdio.h>

int main(void) {
    int array[] = {2, 8, 18, 22, 100, 110, 222};
    int low = 0;
    int high = 7 - 1;
    int mid = 0;
    int value = 18;

    while (low <= high) {
        mid = (low + high) / 2;

        if (array[mid] > value)
            high = mid - 1;
        if (array[mid] < value)
            low = mid + 1;
        else {
            printf("Number %d found at the index %d\n", value, mid - 1);
            break;
        }

        if (low > high) {
            printf("Number not found\n");
        }
    }

    return 0;
}