#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 9

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) return -1;
    /*
    Ovo provjerava je li queue početno prazan prije nego što 
    pokušamo dequeue-ati.
    */
    Node *temp = front;
    int value = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    /*
    Ako je queue imao samo jedan element, pomicanje front na 
    next (koji je NULL) znači da je queue sada prazan. U tom 
    slučaju, moramo ažurirati i rear na NULL, jer inače rear 
    bi ostao "visiti" i pokazivao na obrisani node (što može 
    dovesti do bugova kasnije, npr. prilikom enqueue-a).
    */
    free(temp);
    return value;
}

// Missing implementations for is_empty(), add_edge(), bfs() and main() functions