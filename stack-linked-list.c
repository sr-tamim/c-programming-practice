#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

struct Node *getNewNode()
{
    return (struct Node *)malloc(sizeof(struct Node));
}

int isEmpty()
{
    return top == NULL ? 1 : 0;
}

void push(int data)
{
    struct Node *newNode = getNewNode();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (isEmpty() == 1)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    free(temp);
}

int peek()
{
    if (isEmpty() == 1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
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
    pop();
    return 0;
}
