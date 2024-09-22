#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

LinkedList newLinkedList();

void insertIntoLinkedListAt(LinkedList *ll, int item, int pos);

void removeFromLinkedList(LinkedList *ll, int item);

void displayLinkedList(LinkedList ll);

#endif