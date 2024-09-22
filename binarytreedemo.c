#include <stdio.h>
#include "structures/binarytree.h"

/* INPUT TREE:
         1
        / \
       2  3
     / \   \
    4  5   6
*/

int main() {
    BinaryTree tree = newBinaryTree();

    insertIntoTreeAt(&tree, 1, "");
    insertIntoTreeAt(&tree, 2, "L");
    insertIntoTreeAt(&tree, 3, "R");
    insertIntoTreeAt(&tree, 4, "LL");
    insertIntoTreeAt(&tree, 5, "LR");
    insertIntoTreeAt(&tree, 6, "RR");

    printf("Preorder: ");
    preorderTraversalRecursive(tree.root);
    printf("\n");

    printf("Inorder: ");
    inorderTraversalRecursive(tree.root);
    printf("\n");

    printf("Postorder: ");
    postorderTraversalRecursive(tree.root);
    printf("\n");

    return 0;
}