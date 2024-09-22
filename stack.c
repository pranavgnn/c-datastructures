#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int size;
    int* items;
} Stack;

Stack newStack(int size) {
    return (Stack) {-1, size, (int*) malloc(size * sizeof(int))};
    /* Alternatively:
        Stack s;
        s.size = size;
        s.top = -1;
        s.items = (int*) malloc(size * sizeof(int));
        return s;
    */
}

int isFull(Stack s) {
    return s.top == s.size - 1;
}

int isEmpty(Stack s) {
    return s.top < 0;
}

void push(Stack* s, int item) {
    if (isFull(*s))
        printf("Stack overflow\n");
    else
        s->items[++(s->top)] = item;
}

int pop(Stack* s) {
    if (isEmpty(*s))
        printf("Stack underflow\n");
    else
        return s->items[(s->top)--];
}

void display(Stack s) {
    printf("Stack: ");
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.items[i]);
    }
    printf("\n");
}

int main() {
    printf("--STACK USING ARRAY IMPLEMENTATION--\n");

    int n, x, i;
    
    printf("Enter stack size: ");
    scanf("%d", &n);

    Stack s = newStack(n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        push(&s, x);
        display(s);
    }

    while (!isEmpty(s)) {
        pop(&s);
        display(s);
    }

    return 0;
}