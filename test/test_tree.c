#include "tree.h"
#include <stdio.h>

void test_tree(void) {
    Node* root = createSampleTree();
    printf("Preorder: ");
    preorder(root);
    printf("\n");
}
