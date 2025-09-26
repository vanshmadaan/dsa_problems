#include <stdio.h>
#define MAX 100000

typedef struct MyQueue {
    int front;
    int rear;
    int arr[MAX];
} MyQueue;

void initQueue(struct MyQueue* queue){
    queue->rear = -1;
    queue->front = -1;
}

int isFull(struct MyQueue* queue){
    return (queue->rear+1) % MAX == queue->front;
}

int isEmpty(struct MyQueue* queue){
    return queue->front == -1;
}

void push(struct MyQueue* queue, int a){
    if (isFull(queue)){
        return;
    }
    if (queue->front == -1){
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = a;
}

int pop(struct MyQueue* queue){
    if (isEmpty(queue)){
        return -1;
    }

    int value = queue->arr[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % MAX;
    }
    return value;
}


int main(){
    MyQueue queue;
    initQueue(&queue);
    
    push(&queue, 10);
    push(&queue, 20);
    push(&queue,30);

    int x = pop(&queue);
    if (x != -1) {
        printf("Popped element is %d\n", x);
    } 
    else {
        printf("Queue is empty\n");
    }


    return 0;
}
