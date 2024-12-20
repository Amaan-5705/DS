#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newnode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insertNode(struct Node* node, int value) {
    if (node == NULL) {
        return newnode(value);
    }
    if (value < node->data) {
        node->left = insertNode(node->left, value);
    } else if (value > node->data) {
        node->right = insertNode(node->right, value);
    }
    return node;
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->data);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf(" %d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int value, n;

    // Ask user for number of nodes
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Insert n values into the tree
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    // Perform the tree traversals
    printf("Postorder:\n");
    postOrder(root);
    printf("\n");

    printf("Preorder:\n");
    preOrder(root);
    printf("\n");

    printf("Inorder:\n");
    inOrder(root);
    printf("\n");

    return 0;
}
