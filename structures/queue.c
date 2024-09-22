#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue newQueue(int size) {
    return (Queue) {0, -1, size, (int*) malloc(1000 * sizeof(int))};
    /* Alternatively:
        Queue q;
        q.front = 0;
        q.rear = -1;
        q.size = size;
        q.items = (int*) malloc(size * sizeof(int));
        return q;
    */
}

int isQueueFull(Queue q) {
    return (q.rear - q.front) == q.size - 1;
}

int isQueueEmpty(Queue q) {
    return q.front > q.rear;
}

void enqueue(Queue *q, int item) {
    if (isQueueFull(*q))
        printf("Queue overflow\n");
    else
        q->items[++(q->rear)] = item;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(*q))
        printf("Queue underflow\n");
    else
        return q->items[(q->front)++];
}

void displayQueue(Queue q) {
    printf("Queue: ");

    if (isQueueEmpty(q))
        printf("Empty");
    else
        for (int i = q.front; i <= q.rear; i++)
            printf("%d ", q.items[i]);

    printf("\n");
}