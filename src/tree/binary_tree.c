#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Node* createSampleTree(void) {
    Node *a = malloc(sizeof(Node));
    Node *b = malloc(sizeof(Node));
    Node *c = malloc(sizeof(Node));
    a->data = 'A'; b->data = 'B'; c->data = 'C';
    a->left = b; a->right = c;
    b->left = b->right = c->left = c->right = NULL;
    return a;
}

void preorder(Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
