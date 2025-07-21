#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(char value, Node *left, Node *right) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

Node *create_tree(char values[], int i, int size) {
    if (i >= size)
        return NULL;
    else
        return create_node(values[i], create_tree(values, 2 * i + 1, size), create_tree(values, 2 * i + 2, size));
}

void insert_node(Node *node, Node *newNode) {
    if ((node->right == NULL) && (node->value < newNode->value))
        node->right = newNode;
    else if ((node->right != NULL) && (node->value < newNode->value))
        insert_node(node->right, newNode);
    if ((node->left == NULL) && (node->value > newNode->value))
        node->left = newNode;
    else if ((node->left != NULL) && (node->value > newNode->value))
        insert_node(node->left, newNode);
}

int search_node(Node *node, int target) {
    while (node != NULL) {
        if (target > node->value)
            node = node->right;
        else if (target < node->value)
            node = node->left;
        else
            return 1;
    }
    return 0;
}

int main(void) {
    char values[] = {'g', 'd', 'i', 'b', 'f'};
    Node *root;
    root = create_tree(values, 0, 5);
    return 0;
}