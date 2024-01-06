#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    struct Node *next;
}Node;

Node *create_linked_list(void) {
    int no_of_elements;
    Node *head, *current;

    printf("Define the size of a linked list: ");
    scanf("%d", &no_of_elements);

    srand(time(0));

    for (int i = 0; i < no_of_elements; i++) {
        if (i == 0) {
            head = (Node*)malloc(sizeof(Node));
            current = head;
        }
        else {
            current->next = (Node*)malloc(sizeof(Node));
            current = current->next;
        }
        // printf("Enter the value for an element: ");
        // scanf("%d", &current->value);
        current->value = rand() % 100;
    }
    current->next = NULL;
    
    return head;
}

void print_linked_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    print_linked_list(create_linked_list());
    return 0;
}