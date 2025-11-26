#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data
    newNode->data = data;
    
    // Initialize children as NULL (Leaf node by default)
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

// Helper function to display the tree (In-order traversal)
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d -> ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = createNode(1);
    struct Node* p1 = createNode(2);
    struct Node* p2 = createNode(3);
    struct Node* p3 = createNode(4);
    struct Node* p4 = createNode(5);

    

    // 4. Linking the nodes together
    root->left = p1;   // Link 2 to left of 1
    root->right = p2;  // Link 3 to right of 1
    
    p1->left = p3;     // Link 4 to left of 2
    p1->right = p4;    // Link 5 to right of 2

    printf("Binary Tree created successfully.\n");
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("NULL\n");

    return 0;
}
