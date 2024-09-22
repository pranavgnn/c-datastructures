#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int size;
    int* items;
} Queue;

Queue newQueue(int size) {
    return (Queue) {0, -1, size, (int*) malloc(size * sizeof(int))};
    /* Alternatively:
        Queue q;
        q.front = 0;
        q.rear = -1;
        q.size = size;
        q.items = (int*) malloc((size + 1) * sizeof(int));
        return q;
    */
}

void enqueue(Queue *q, int item) {
    q->rear = (q->rear + 1) % q->size;
    q->items[q->rear] = item;
}

int dequeue(Queue *q) {
    int removedItem = q->items[q->front];
    q->front = (q->front + 1) % q->size;

    return removedItem;
}

void display(Queue q) {
    printf("Queue: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.items[i]);
    }
    printf("\n");
}

int main() {
    printf("--CIRCULAR QUEUE USING ARRAY IMPLEMENTATION--\n");

    int n, x, i;
    
    printf("Enter queue size: ");
    scanf("%d", &n);

    Queue q = newQueue(n);

    printf("Enter %d elements: ", 2*n);
    for (i = 0; i < 2*n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
        display(q);
    }

    
    // while (!isEmpty(q)) {
    //     dequeue(&q);
    //     display(q);
    // }

    return 0;
}