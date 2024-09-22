#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

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

int isStackFull(Stack s) {
    return s.top == s.size - 1;
}

int isStackEmpty(Stack s) {
    return s.top < 0;
}

void pushToStack(Stack* s, int item) {
    if (isStackFull(*s))
        printf("Stack overflow\n");
    else
        s->items[++(s->top)] = item;
}

int popFromStack(Stack* s) {
    if (isStackEmpty(*s))
        printf("Stack underflow\n");
    else
        return s->items[(s->top)--];
}

void displayStack(Stack s) {
    printf("Stack: ");
    
    if (isStackEmpty(s))
        printf("Empty");
    else
        for (int i = 0; i <= s.top; i++)
            printf("%d ", s.items[i]);
            
    printf("\n");
}