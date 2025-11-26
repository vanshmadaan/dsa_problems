#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Code for insertion
struct Node* insert(struct Node* node, int value) {
    if (node == NULL) return createNode(value);

    // If value is smaller, go to the left child
    if (value < node->data)
        node->left = insert(node->left, value);
    
    // If value is larger, go to the right child
    else if (value > node->data)
        node->right = insert(node->right, value);

    // Return the unchanged node pointer
    return node;
}

// Code for searching
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    // Key is greater than root's data -> Search Right
    if (root->data < key)
        return search(root->right, key);
    
    // Key is smaller than root's data -> Search Left
    return search(root->left, key);
}

// In-order traversal (Always prints BST in sorted order)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order Traversal (Sorted): \n");
    inorder(root);
    printf("NULL\n\n");

    int key = 60;
    if (search(root, key) != NULL)
        printf("Element %d found in the tree.\n", key);
    else
        printf("Element %d NOT found.\n", key);

    return 0;
}
