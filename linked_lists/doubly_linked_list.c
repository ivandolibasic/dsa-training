#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node *previous;
    struct Node *next;
} Node;

Node *add_to_front(Node *head, int x) {
    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    temp->value = x;
    temp->previous = NULL;
    temp->next = head;
    if (head != NULL) {
        head->previous = NULL;
    }
    return temp;
}

void add_to_back(Node *head, int x) {
    if (head != NULL) {
        Node *temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        Node *temp2 = (Node*)malloc(sizeof(Node));
        temp2->value = x;
        temp2->previous = temp1;
        temp2->next = NULL;
        temp1->next = temp2;
    }
}

void print_doubly_linked_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

Node *create_list(int length, int upperLimit) {
    Node *head = NULL, *current = NULL;

    for (int i = 0; i < length; i++) {
        if (head == NULL) {
            head = (Node*)malloc(sizeof(Node));
            current = head;
            current->previous = NULL;
        }
        else {
            current->next = (Node*)malloc(sizeof(Node));
            current->next->previous = current;
            current = current->next;
        }
        current->value = rand() % upperLimit;
        current->next = NULL;
    }
    return head;
}

int main(void) {
    int len, lim;

    printf("Define the length of the list: ");
    scanf("%d", &len);
    printf("Define the upper limit of each element: ");
    scanf("%d", &lim);

    Node *head = create_list(len, lim);

    print_doubly_linked_list(head);

    return 0;
}