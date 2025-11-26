#include <stdio.h>
#include <stdbool.h>

#define MAX 10 // Maximum number of vertices

int adj[MAX][MAX]; // Adjacency Matrix
int visited[MAX];  // Visited array
int n;             // Number of vertices


int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    rear++;
    queue[rear] = item;
}

int dequeue() {
    if (front == -1 || front > rear) return -1; 
    int item = queue[front];
    front++;
    return item;
}

bool isQueueEmpty() {
    return (front == -1 || front > rear);
}


void BFS(int startNode) {
    // 1. Mark start node as visited and enqueue it
    visited[startNode] = 1;
    enqueue(startNode);
    
    printf("BFS Traversal: ");

    while (!isQueueEmpty()) {
        // 2. Dequeue the current node and print it
        int current = dequeue();
        printf("%d ", current);

        // 3. Visit all adjacent vertices of the current node
        for (int i = 0; i < n; i++) {
            // Check if there is an edge (adj[current][i] == 1)
            // AND if the neighbor 'i' has not been visited yet
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1; // Mark as visited immediately
                enqueue(i);     // Add to queue
            }
        }
    }
    printf("\n");
}

int main() {
    // Let's create a graph with 5 nodes (0 to 4)
    n = 5;

    // Reset visited array and matrix
    for(int i=0; i<n; i++) {
        visited[i] = 0;
        for(int j=0; j<n; j++) adj[i][j] = 0;
    }

    // Define edges
    // Connect 0-1
    adj[0][1] = 1; adj[1][0] = 1;
    // Connect 0-2
    adj[0][2] = 1; adj[2][0] = 1;
    // Connect 1-3
    adj[1][3] = 1; adj[3][1] = 1;
    // Connect 2-3
    adj[2][3] = 1; adj[3][2] = 1;
    // Connect 3-4
    adj[3][4] = 1; adj[4][3] = 1;

    // Run BFS starting from Node 0
    BFS(0);

    return 0;
}
