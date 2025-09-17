#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *create_node(int data) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

void insert(Node *root, Node *new) {
    if (new->data < root->data) {
        if (root->left == NULL) root->left = new;
        else insert(root->left, new);
    }
    else if (new->data > root->data) {
        if (root->right == NULL) root->right = new;
        else insert(root->right, new);
    }
    else
        free(new);
}

int find_maxleft(Node *root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int find_minright(Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

void print_maxleft_minright_product(Node *root) {
    if (root == NULL || root->left == NULL || root->right == NULL) {
        printf("0");
        return;
    }
    int max = find_maxleft(root->left);
    int min = find_minright(root->right);
    printf("%d", max * min);
}

int main(void) {
    FILE *f = fopen("subtree.txt", "r");
    int n, input[10];
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &input[i]);
    Node *root = create_node(input[0]);
    for (int i = 0; i < n; i++) {
        Node *new = create_node(input[i]);
        insert(root, new);
    }
    print_maxleft_minright_product(root);
    return 0;
}