#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_list(int length, int upperLimit) {
    Node *head = NULL, *current = NULL;
    srand(time(0));
    for (int i = 0; i < length; i++) {
        if (head == NULL) {
            head = (Node*)malloc(sizeof(Node));
            current = head;
        }
        else {
            current->next = (Node*)malloc(sizeof(Node));
            current = current->next;
        }
        current->value = rand() % upperLimit;
    }
    return head;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

int main(void) {
    int length, upperLimit;

    printf("Enter list length: ");
    scanf("%d", &length);
    printf("Define the upper limit value for each list element: ");
    scanf("%d", &upperLimit);

    Node *head = create_list(length, upperLimit);
    print_list(head);

    return 0;
}