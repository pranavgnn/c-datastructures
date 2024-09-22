#include <stdio.h>
#include "structures/linkedlist.h"

int main() {
    LinkedList ll = newLinkedList();
    int choice, item, pos;

    printf("--LINKED LIST--\n");

    while(1) {
        printf("\t1: Insert\n\t2: Delete\n\t3: Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter item to insert and its position: ");
            scanf("%d %d", &item, &pos);

            if (pos < 1) {
                printf("Invalid position! Position must be greater than or equal to 1\n");
                break;
            }

            insertIntoLinkedListAt(&ll, item, pos - 1);

            break;
        
        case 2:
            printf("Enter item to remove: ");
            scanf("%d", &item);

            removeFromLinkedList(&ll, item);

            break;
            
        default:
            return 0;
        }
    
        displayLinkedList(ll);
        printf("\n");
    }

    return 0;
}