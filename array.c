#include <stdio.h>

#define Max 100
int top = -1;
int stack[Max];

void push(int x)
{
    if (top == Max - 1)
    {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

int main()
{
    int choice;
    int x;

    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            if (x != -1)
                printf("Popped element is %d\n", x);
            break;
        case 3:
            if (top == -1)
            {
                printf("Stack is empty\n");
                break;
            }
            printf("Stack elements are: ");
            for (int i = 0; i <= top; i++)
                printf("%d ", stack[i]);
            printf("\n");
            break;

        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
