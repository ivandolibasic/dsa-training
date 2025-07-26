#include <stdio.h>

int queue[256] = {0};
int count = 0;

void enqueue(int x) {
    queue[count] = x;
    count++;
}

int dequeue(void) {
    int result = queue[0];
    for (int i = 0; i < count - 1; i++)
        queue[i] = queue[i + 1];
    count--;
    return result;
}

int main(void) {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    dequeue();
    enqueue(5);

    int length = count;
    for (int i = 0; i < length; i++) {
        printf("%d ", dequeue());
    }
    printf("\n");

    return 0;
}