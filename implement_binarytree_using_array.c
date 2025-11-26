#include <stdio.h>

#define MAX_SIZE 15

char tree[MAX_SIZE];


void init_tree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = '\0';
    }
}


void set_root(char key) {
    if (tree[0] != '\0') {
        printf("Root already exists.\n");
    } else {
        tree[0] = key;
    }
}

// Function to set the left child
void set_left(char key, int parent_index) {
    int left_child_index = (2 * parent_index) + 1;
    
    // Check for array bounds
    if (left_child_index >= MAX_SIZE) {
        printf("Index out of bounds (Tree is full)\n");
        return;
    }

    // Check if parent exists
    if (tree[parent_index] == '\0') {
        printf("Cannot set left child: Parent at index %d does not exist.\n", parent_index);
    } else {
        tree[left_child_index] = key;
    }
}

// Function to set the right child
void set_right(char key, int parent_index) {
    int right_child_index = (2 * parent_index) + 2;

    // Check for array bounds
    if (right_child_index >= MAX_SIZE) {
        printf("Index out of bounds (Tree is full)\n");
        return;
    }

    // Check if parent exists
    if (tree[parent_index] == '\0') {
        printf("Cannot set right child: Parent at index %d does not exist.\n", parent_index);
    } else {
        tree[right_child_index] = key;
    }
}

void print_tree() {
    printf("\nTree Array Representation:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] != '\0')
            printf("%d:%c | ", i, tree[i]);
        else
            printf("%d:- | ", i);
    }
    printf("\n");
}

int main() {
    init_tree();

    set_root('A');
    
    set_left('B', 0); 
    set_right('C', 0); 
    
    set_left('D', 1);  
    set_right('E', 1);

    set_right('F', 2);

    print_tree();

    return 0;
}
