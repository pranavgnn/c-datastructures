#ifndef STACK_H
#define STACK_H

typedef struct {
    int top;
    int size;
    int* items;
} Stack;

Stack newStack(int size);

int isStackFull(Stack s);

int isStackEmpty(Stack s);

void pushToStack(Stack* s, int item);

int popFromStack(Stack* s);

void displayStack(Stack s);

#endif