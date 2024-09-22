#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *leftChild, *rightChild;
} Node;

Node newNode(int data) {
    return (Node) {data, NULL, NULL};
}

void insertAt(Node **root, int item, char direction[]) {
    Node *temp = *root;
    int i;
    char x;

    Node *nodeToInsert = (Node*) malloc(sizeof(Node));
    nodeToInsert->data = item;
    nodeToInsert->leftChild = NULL;
    nodeToInsert->rightChild = NULL;

    if (temp == NULL) {
        *root = nodeToInsert;
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

/* INPUT TREE:
         1
        / \
       2  3
     / \   \
    4  5   6
*/

int main() {
    Node *root = NULL;
    insertAt(&root, 1, "");
    insertAt(&root, 2, "L");
    insertAt(&root, 3, "R");
    insertAt(&root, 4, "LL");
    insertAt(&root, 5, "LR");
    insertAt(&root, 6, "RR");

    printf("Preorder: ");
    preorderTraversalRecursive(root);
    printf("\n");

    printf("Inorder: ");
    inorderTraversalRecursive(root);
    printf("\n");

    printf("Postorder: ");
    postorderTraversalRecursive(root);
    printf("\n");

    return 0;
}