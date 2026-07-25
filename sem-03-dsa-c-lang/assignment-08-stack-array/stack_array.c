#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;   // an empty stack is represented by top == -1

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d.\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed onto the stack.\n", value);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    printf("%d popped from the stack.\n", stack[top--]);
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty, nothing to peek.\n");
        return;
    }
    printf("Top element is %d.\n", stack[top]);
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (top element)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
