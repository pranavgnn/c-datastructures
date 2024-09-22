#include <stdio.h>
#include "structures/queue.h"

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
        displayQueue(q);
    }

    while (!isQueueEmpty(q)) {
        dequeue(&q);
        displayQueue(q);
    }

    return 0;
}