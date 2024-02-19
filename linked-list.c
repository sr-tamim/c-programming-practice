#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d", n->data);
        n = n->next;
        if (n != NULL)
            printf(" -> ");
    }
    printf("\n");
}

struct Node *getNewNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    return newNode;
}

int getElementIndex(struct Node *head, int data)
{
    struct Node *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == data)
            return index;
        index++;
        temp = temp->next;
    }
    return -1;
}

void insertAtFront(struct Node **head, int data)
{
    struct Node *newNode = getNewNode();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = getNewNode();
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtIndex(struct Node **head, int data, int index)
{
    struct Node *newNode = getNewNode();
    newNode->data = data;
    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfterElement(struct Node **head, int data, int element)
{
    struct Node *newNode = getNewNode();
    newNode->data = data;
    int elementIndex = getElementIndex(*head, element);
    if (elementIndex == -1)
    {
        printf("Element not found\n");
        return;
    }
    insertAtIndex(head, data, elementIndex + 1);
}

void deleteNode(struct Node **head, int index)
{
    struct Node *temp = *head;
    if (index == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;
    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void deleteElement(struct Node **head, int element)
{
    int elementIndex = getElementIndex(*head, element);
    if (elementIndex == -1)
    {
        printf("Element not found\n");
        return;
    }
    deleteNode(head, elementIndex);
}

void reverseList(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

struct Node *isContainCycle(struct Node *head)
{
    // check for cycle and return the node where the cycle starts
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct Node *temp = head;
            while (temp != slow)
            {
                temp = temp->next;
                slow = slow->next;
            }
            return temp;
        }
    }
    return NULL;
}

int main()
{
    struct Node *head = NULL;

    // Insert 5 at the beginning
    insertAtFront(&head, 5);

    // Add 10 to the end
    insertAtEnd(head, 10);

    // Add 15 to the end
    insertAtEnd(head, 15);

    // Insert 25 after 10
    insertAfterElement(&head, 25, 10);

    // Delete the node with the value 10
    // deleteElement(&head, 10);

    // Insert 20 at position 2
    insertAtIndex(&head, 20, 2);

    // Delete the node at position 3
    // deleteNode(&head, 3);

    // Reverse the list
    // reverseList(&head);

    // Print the list
    printList(head);

    // create a cycle
    printf("Creating a cycle...\nNode 15 -> Node 10\n");
    struct Node *cycleNode = head->next;
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = cycleNode;

    // Check if the list contains a cycle
    printf("\nChecking if the list contains a cycle...\n");
    struct Node *cycleStarts = isContainCycle(head);
    printf("Has Cycle: ");
    if (cycleStarts != NULL)
    {
        printf("Yes\n");
        printf("Cycle Start Node: %d\n", cycleStarts->data);
    }
    else
    {
        printf("No\n");
    }
}