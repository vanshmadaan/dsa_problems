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
    return queue->rear == MAX-1;
}

int isEmpty(struct MyQueue* queue){
    return queue->rear == -1;
}

void push(struct MyQueue* queue, int a){
    if (isFull(queue)){
        return;
    }
    if (queue->front == -1){
        queue->front = 0;
    }
    queue->arr[++queue->rear] = a;
}

int pop(struct MyQueue* queue){
    if (isEmpty(queue)){
        return -1;
    }
    return queue->arr[queue->front++];
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
