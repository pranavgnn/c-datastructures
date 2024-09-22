#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *leftChild, *rightChild;
} Node;

typedef struct {
    Node *root;
} BinaryTree;

BinaryTree newBinaryTree();

void insertIntoTreeAt(BinaryTree *tree, int item, char direction[]);

void preorderTraversalRecursive(Node *root);

void inorderTraversalRecursive(Node *root);

void postorderTraversalRecursive(Node *root);

#endif