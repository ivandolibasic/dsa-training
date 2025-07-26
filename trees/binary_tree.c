#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int x) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = x;
    node->left = node->right = NULL;
    return node;
}

Node *insert_node(Node *root, int value) {
    Node *node = root;
    if (node == NULL)
        return create_node(value);
    if (value <= node->value)
        node->left = insert_node(node->left, value);
    else
        node->right = insert_node(node->right, value);
    return node;
}

Node *create_tree(int *arr, int length) {
    Node *root = NULL;
    for (int i = 0; i < length; i++) {
        int value = arr[i];
        root = insert_node(root, value);
    }
    return root;
}

void preorder_traversal(Node *root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(Node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->value);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(Node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->value);
    }
}

int linear_search(int *arr, int length, int target) {
    for (int i = 0; i < length; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

Node *build_tree(int *preorder, int *inorder, int n) {
    if (n == 0)
        return NULL;
    Node *root = create_node(preorder[0]);
    int mid = linear_search(inorder, n, preorder[0]);
    root->left = build_tree(preorder + 1, inorder, mid);
    root->right = build_tree(preorder + 1 + mid, inorder + mid + 1, n - mid - 1);
    return root;
}

int main(void) {
    // int arr[] = {19, 7, 4, 9, 11, 2, 15, 8, 3, 18};
    // int len = sizeof(arr) / sizeof(int);

    // Node *root = create_tree(arr, len);
    
    // printf("Preorder traversal: ");
    // preorder_traversal(root);
    // printf("\nInorder traversal: ");
    // inorder_traversal(root);
    // printf("\nPostorder traversal: ");
    // postorder_traversal(root);

    int preorder[] = {3, 9, 20, 15, 7}, inorder[] = {9, 3, 15, 20, 7}, n = 5;
    Node *tree = build_tree(preorder, inorder, n);
    printf("Preorder traversal: ");
    preorder_traversal(tree);
    printf("\nInorder traversal: ");
    inorder_traversal(tree);

    return 0;
}

// Another implementation

// typedef struct Node {
//     char value;
//     struct Node *left;
//     struct Node *right;
// } Node;

// Node *create_node(char value, Node *left, Node *right) {
//     Node *node = (Node*)malloc(sizeof(Node));
//     node->value = value;
//     node->left = left;
//     node->right = right;
//     return node;
// }

// Node *create_tree(char values[], int i, int size) {
//     if (i >= size)
//         return NULL;
//     else
//         return create_node(values[i], create_tree(values, 2 * i + 1, size), create_tree(values, 2 * i + 2, size));
// }

// void insert_node(Node *node, Node *newNode) {
//     if ((node->right == NULL) && (node->value < newNode->value))
//         node->right = newNode;
//     else if ((node->right != NULL) && (node->value < newNode->value))
//         insert_node(node->right, newNode);
//     if ((node->left == NULL) && (node->value > newNode->value))
//         node->left = newNode;
//     else if ((node->left != NULL) && (node->value > newNode->value))
//         insert_node(node->left, newNode);
// }

// int search_node(Node *node, int target) {
//     while (node != NULL) {
//         if (target > node->value)
//             node = node->right;
//         else if (target < node->value)
//             node = node->left;
//         else
//             return 1;
//     }
//     return 0;
// }

// int main(void) {
//     char values[] = {'g', 'd', 'i', 'b', 'f'};
//     Node *root;
//     root = create_tree(values, 0, 5);
//     return 0;
// }