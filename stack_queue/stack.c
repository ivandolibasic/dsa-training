#include <stdio.h>

int stack[4], count = 0;

void push(int value) {
    int size = sizeof(stack) / sizeof(int);
    if (count == size) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    stack[count] = value;
    count++;
}

int pop(void) {
    if (count == 0) {
        fprintf(stderr, "Stack underflow\n");
        return -1;
    }
    int value = stack[count - 1];
    count--;
    return value;
}

int main(void) {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    int length = count;
    for (int i = 0; i < length; i++)
        printf("%d ", pop());

    int x = pop();

    return 0;
}