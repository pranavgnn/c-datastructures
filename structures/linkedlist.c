#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

LinkedList newLinkedList() {
    return (LinkedList) {NULL};
    /* Alternatively:
        LinkedList ll;
        ll.head = NULL;
        return ll;
    */
}

void insertIntoLinkedListAt(LinkedList *ll, int item, int pos) {
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

void removeFromLinkedList(LinkedList *ll, int item) {
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

void displayLinkedList(LinkedList ll) {
    Node *temp = ll.head;

    printf("Linked List: ");

    if (temp == NULL)
        printf("Empty");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}