#include <stdio.h>

int stack[4];
int count = 0;

void push(int x) {
    size_t stack_size = sizeof(stack) / sizeof(int);
    if (count == stack_size) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    stack[count] = x;
    count++;
}

int pop() {
    if (count == 0) {
        fprintf(stderr, "Stack underflow\n");
        return -1;
    }
    int result = stack[count - 1];
    count--;
    return result;
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    int length = count;
    for (int i = 0; i < length; i++) {
        printf("%d ", pop());
    }
    printf("\n");

    int x = pop();

    return 0;
}