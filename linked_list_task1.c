#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_list() {
    Node *head = NULL, *current = NULL;
    int value;

    do {
        printf("Enter a value: ");
        scanf("%d", &value);

        if (head == NULL) {
            head = (Node*)malloc(sizeof(Node));
            head->value = value;
            current = head;
        }
        else {
            current->next = (Node*)malloc(sizeof(Node));
            current = current->next;
            current->value = value;
        }
    } while (value != 0);

    return head;
}

Node *insert_between(Node *head, int x, int y, int z) {
    Node *current = head, *helper = NULL, *new = NULL;
    int count = 0;
    while (current != NULL) {
        if (current->value == x) {
            helper = current->next;
            if (helper->value == y) {
                // count++;
                new = (Node*)malloc(sizeof(Node));
                new->value = z;
                new->next = helper;
                current->next = new;
            }
        }
        current = current->next;
    }
    // printf("Count: %d\n", count);
    return head;
}

Node *insert_tail(Node *head, int insertValue) {
    Node *current = head, *new = NULL;
    while (current != NULL) {
        if (current->next == NULL) {
            new = (Node*)malloc(sizeof(Node));
            current->next = new;
            current = current->next;
            break;
        }
        current = current->next;
    }
    current->value = insertValue;
    return head;
}

Node *insert_head(Node *head, int insertValue) { // push() equivalent
    Node *new = (Node*)malloc(sizeof(Node));
    new->next = head;
    new->value = insertValue;
    return new;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

Node *push(Node *top, int value) {
    return insert_head(top, value);
}

int main() {
    Node *list = create_list(); // Input: 4 6 7 2 3 4 6 9 8 4 6 0
    print_list(list);
    // insert_between(list, 4, 6, 10);
    // print_list(list); // Output: 4 10 6 7 2 3 4 10 6 9 8 4 10 6 0

    Node *addedTail = insert_tail(list, 2);
    print_list(addedTail);

    Node *addedHead = insert_head(addedTail, 222);
    print_list(addedHead);

    return 0;
}