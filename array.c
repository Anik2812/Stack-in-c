#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack stack) {
    stack.top = -1;
}

bool isFull(Stack stack) {
    return stack.top == MAX_SIZE - 1;
}

bool isEmpty(Stack stack) {
    return stack.top == -1;
}

void push(Stack stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push element.\n");
        return;
    }
    stack.arr[++stack.top] = value;
    printf("%d pushed to the stack.\n", value);
}

void pop(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop element.\n");
        return;
    }
    int value = stack.arr[stack.top--];
    printf("%d popped from the stack.\n", value);
}

void display(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.arr[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    int choice, value;

    initStack(stack);

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
