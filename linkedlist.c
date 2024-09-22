#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

LinkedList newLinkedList() {
    return (LinkedList) {NULL};
    /* Alternatively:
        LinkedList ll;
        ll.head = NULL;
        return ll;
    */
}

void insertAt(LinkedList *ll, int item, int pos) {
    Node *nodeToAdd = (Node*) malloc(sizeof(Node));  
    Node *temp = ll->head;
    Node *prev = temp;

    nodeToAdd->data = item;
    nodeToAdd->next = NULL;

    if (temp == NULL) {
        ll->head = nodeToAdd;
        return;
    }

    for (int i = 0; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    nodeToAdd->next = prev->next;
    prev->next = nodeToAdd;
}

void removeFrom(LinkedList *ll, int item) {
    Node *temp = ll->head;
    Node *prev = temp;

    if (temp == NULL) return;

    while (temp->data != item && temp != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;

    if (temp == ll->head)
        ll->head = NULL;
}

void display(LinkedList ll) {
    Node *temp = ll.head;

    printf("Linked List: ");

    if (temp == NULL) {
        printf("Empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

int main() {
    LinkedList ll = newLinkedList();
    int choice, item, pos;

    printf("--LINKED LIST--");

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

            insertAt(&ll, item, pos - 1);

            break;
        
        case 2:
            printf("Enter item to remove: ");
            scanf("%d", &item);

            removeFrom(&ll, item);

            break;
            
        default:
            return 0;
        }

    
        display(ll);
        printf("\n");
    }

    return 0;
}