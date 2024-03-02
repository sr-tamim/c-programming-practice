#include<stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty()
{
    return top == -1 ? 1 : 0;
}

int isFull()
{
    return top == MAX - 1 ? 1 : 0;
}

void push(int data)
{
    if (isFull() == 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = data;
}

void pop()
{
    if (isEmpty() == 1)
    {
        printf("Stack underflow\n");
        return;
    }
    top--;
}

int peek()
{
    if (isEmpty() == 1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int main()
{
    push(1);
    push(2);
    push(3);
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());
    return 0;
}