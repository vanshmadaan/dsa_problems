#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void preorderTraversal(struct Node* root) {
    if (root == NULL) return; 
    
    printf("%d ", root->data);      // Process Root
    preorderTraversal(root->left);  // Left
    preorderTraversal(root->right); // Right
}


void inorderTraversal(struct Node* root) {
    if (root == NULL) return; 

    inorderTraversal(root->left);   // Left
    printf("%d ", root->data);      // Process Root
    inorderTraversal(root->right);  // Right
}


void postorderTraversal(struct Node* root) {
    if (root == NULL) return; 

    postorderTraversal(root->left);   // Left
    postorderTraversal(root->right);  // Right
    printf("%d ", root->data);        // Process Root
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Pre-order traversal:  ");
    preorderTraversal(root);
    printf("\n");

    printf("In-order traversal:   ");
    inorderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
    
