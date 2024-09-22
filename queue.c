#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int size;
    int* items;
} Queue;

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

int isFull(Queue q) {
    return (q.rear - q.front) == q.size - 1;
}

int isEmpty(Queue q) {
    return q.front > q.rear;
}

void enqueue(Queue *q, int item) {
    if (isFull(*q))
        printf("Queue overflow\n");
    else
        q->items[++(q->rear)] = item;
}

int dequeue(Queue *q) {
    if (isEmpty(*q))
        printf("Queue underflow\n");
    else
        return q->items[(q->front)++];
}

void display(Queue q) {
    printf("Queue: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.items[i]);
    }
    printf("\n");
}

int main() {
    printf("--QUEUE USING ARRAY IMPLEMENTATION--\n");

    int n, x, i;
    
    printf("Enter queue size: ");
    scanf("%d", &n);

    Queue q = newQueue(n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
        display(q);
    }

    while (!isEmpty(q)) {
        dequeue(&q);
        display(q);
    }

    return 0;
}