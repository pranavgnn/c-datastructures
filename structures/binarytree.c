#include <stdio.h>
#include <stdlib.h>

#include "binarytree.h"

BinaryTree newBinaryTree() {
    return (BinaryTree) {NULL};
}

void insertIntoTreeAt(BinaryTree *tree, int item, char direction[]) {
    Node *temp = tree->root;
    int i;
    char x;

    Node *nodeToInsert = (Node*) malloc(sizeof(Node));
    nodeToInsert->data = item;
    nodeToInsert->leftChild = NULL;
    nodeToInsert->rightChild = NULL;

    if (temp == NULL) {
        tree->root = nodeToInsert;
        return;
    }

    for (i = 0; temp != NULL && direction[i + 1] != '\0'; i++)
        temp = (direction[i] == 'L' || direction[i] == 'l') ? temp->leftChild : temp->rightChild;

    if (direction[i] == 'L' || direction[i] == 'l')
        temp->leftChild = nodeToInsert;
    else
        temp->rightChild = nodeToInsert;
}

void preorderTraversalRecursive(Node *root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorderTraversalRecursive(root->leftChild);
    preorderTraversalRecursive(root->rightChild);
}

void inorderTraversalRecursive(Node *root) {
    if (root == NULL) return;

    inorderTraversalRecursive(root->leftChild);
    printf("%d ", root->data);
    inorderTraversalRecursive(root->rightChild);
}

void postorderTraversalRecursive(Node *root) {
    if (root == NULL) return;

    postorderTraversalRecursive(root->leftChild);
    postorderTraversalRecursive(root->rightChild);
    printf("%d ", root->data);
}