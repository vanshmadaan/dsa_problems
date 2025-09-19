#include <stdio.h>
#define MAX 1000


struct MyStack {
    int top;
    int arr[MAX];
};


void initStack(struct MyStack* stack) {
    stack->top = -1;
}


int isFull(struct MyStack* stack) {
    return stack->top == MAX - 1;
}


int isEmpty(struct MyStack* stack) {
    return stack->top == -1;
}


void push(struct MyStack* stack, int a) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", a);
        return;
    }
    stack->arr[++stack->top] = a;
    printf("%d pushed into stack\n", a);
}


int pop(struct MyStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return stack->arr[stack->top--];
}


void display(struct MyStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements : ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
}

int main() {
    struct MyStack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped element: %d\n", pop(&stack));

    display(&stack);

    return 0;
}