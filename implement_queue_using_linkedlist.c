#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// 2. Define global pointers for Front and Rear
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add an element (Enqueue)
void enqueue(int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty, new node is both front and rear
    if (front == NULL) {
        front = rear = newNode;
    } else {
        // Link the current rear to the new node
        rear->next = newNode;
        // Update rear to point to the new node
        rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Function to remove an element (Dequeue)
void dequeue() {
    // Check if queue is empty
    if (front == NULL) {
        printf("Queue Underflow (Empty)\n");
        return;
    }

    // Store the current front to free it later
    struct Node* temp = front;
    printf("Dequeued: %d\n", front->data);

    // Move front to the next node
    front = front->next;

    // If front becomes NULL, queue is empty, so rear must also be NULL
    if (front == NULL) {
        rear = NULL;
    }

    free(temp); // Free memory
}

// Function to display the queue
void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Test the operations
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    display();
    
    dequeue();
    display();
    
    dequeue();
    dequeue();
    
    // Test underflow
    dequeue(); 
    
    return 0;
}
