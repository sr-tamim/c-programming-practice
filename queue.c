#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->front];
}

int rear(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->rear];
}

void clearMemory(struct Queue *queue)
{
    free(queue->array);
    free(queue);
}

int main()
{
    struct Queue *queue = createQueue(1000);

    enqueue(queue, 5);
    enqueue(queue, 10);

    printf("Front element dequeued %d\n", dequeue(queue));

    printf("Current queue is %d\n", front(queue));

    clearMemory(queue);
    return 0;
}