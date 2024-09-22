#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int front;
    int rear;
    int size;
    int* items;
} Queue;

Queue newQueue(int size);

int isQueueFull(Queue q);

int isQueueEmpty(Queue q);

void enqueue(Queue *q, int item);

int dequeue(Queue *q);

void displayQueue(Queue q);

#endif