#include <stdio.h>
#include "structures/stack.h"

int main() {
    printf("--STACK USING ARRAY IMPLEMENTATION--\n");

    int n, x, i;
    
    printf("Enter stack size: ");
    scanf("%d", &n);

    Stack s = newStack(n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        pushToStack(&s, x);
        displayStack(s);
    }

    while (!isStackEmpty(s)) {
        popFromStack(&s);
        displayStack(s);
    }

    return 0;
}