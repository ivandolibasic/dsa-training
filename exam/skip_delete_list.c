#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node *create_list(int x, int arr[20]) {
    Node *p = NULL, *head = NULL;
    for (int i = 0; i < x; i++) {
        if (i == 0) {
            head = (Node*)malloc(sizeof(Node));
            p = head;
        }
        else {
            p->next = (Node*)malloc(sizeof(Node));
            p = p->next;
        }
        p->data = arr[i];
    }
    p->next = NULL;
    return head;
}

void remove_nodes(Node *head, int m, int n) {
    Node *curr = head, *temp;
    int i;
    while (curr) {
        for (i = 1; i < m; i++)
            curr = curr->next;
        temp = curr->next;
        for (i = 0; i < n && temp != NULL; i++) {
            Node *del = temp;
            temp = temp->next;
            free(del);
        }
        curr->next = temp;
        curr = temp;
    }
}

void print_list(Node *head) {
    Node *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(void) {
    FILE *f = fopen("skip_delete.txt", "r");
    if (!f) return 1;
    int x, m, n;
    int arr[10];
    fscanf(f, "%d", &x);
    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);
    for (int i = 0; i < x; i++) {
        fscanf(f, "%d", &arr[i]);
    }
    Node *head = create_list(x, arr);
    remove_nodes(head, m, n);
    print_list(head);
    fclose(f);
    return 0;
}