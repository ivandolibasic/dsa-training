/*
    1. Stvoriti jednostruko povezanu listu na temelju unesenih cijelih brojeva.
    2. Implementirati funkciju koja pomoću "fast i slow pointer" tehnike pronalazi središnji čvor liste (ako lista ima paran broj elemenata, vrati drugi od dva srednja čvora).
    3. Implementirati funkciju koja pomoću iste tehnike otkriva postoji li ciklus u listi (tj. lista se "vrti" sama u sebe).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int data[] = {7, 4, 9, 2, 6, 8, 1, 5, 0, 3}, len = sizeof(data) / sizeof(int);

int *generate_array(int size) {
    int *arr = (int*)malloc(sizeof(int) * size);
    if (arr == NULL)
        return NULL;
    printf("Enter values for each element:\n");
    int i = 0;
    do {
        scanf("%d", &arr[i]);
        i++;
    } while (i < size);
    return arr;
}

Node *generate_list(int *arr, int length) {
    Node *head = NULL, *current = head;
    for (int i = 0; i < length; i++) {
        if (head == NULL) {
            head = (Node*)malloc(sizeof(Node));
            current = head;
        }
        else {
            current->next = (Node*)malloc(sizeof(Node));
            current = current->next;
        }
        current->next = NULL;
        current->value = arr[i];
    }
    if (head == NULL)
        return NULL;
    return head;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

Node *find_middle_conventional(Node *head) {
    Node *current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    current = head;
    for (int i = 0; i < count / 2; i++) {
        current = current->next;
    }
    return current;
}

Node *find_middle_slow_fast(Node *head) {
    // Node *slow = head, *fast = head->next->next;
    // while (fast != NULL) {
    //     slow = slow->next;
    //     fast = fast->next;
    // }
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool has_cycle(const Node *head) {
    const Node *slow = head, const *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    // int size;
    // printf("Define the size of an array: ");
    // scanf("%d", &size);
    // int *arr = generate_array(size);
    // int length = size;
    Node *list = generate_list(data, len);
    print_list(list);
    printf("\nMiddle element: %d", find_middle_slow_fast(list)->value);
    printf("\n%d", has_cycle(list));
    // free(arr);
    free(list);
    return 0;
}