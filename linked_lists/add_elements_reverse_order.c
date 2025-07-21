#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int data[] = {1, 2, 4, 7, 25, 11};
int length = 6;

Node *create_list(void) {
    Node *head = NULL, *current = NULL;
    for (int i = 0; i < length; i++) {
        if (head == NULL) {
            head = (Node*)malloc(sizeof(Node));
            current = head;
        }
        else {
            current->next = (Node*)malloc(sizeof(Node));
            current = current->next;
        }
        current->value = data[i];
        current->next = NULL;
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

Node *add_elements_in_reverse(Node *head) {
    Node *current = head;
    while (current->next != NULL)
        current = current->next;
    for (int i = length - 1; i >= 0; i--) {
        current->next = (Node*)malloc(sizeof(Node));
        current = current->next;
        current->value = data[i];
        current->next = NULL;
    }
    return head;
}

int main(void) {
    print_list(add_elements_in_reverse(create_list()));
    return 0;
}