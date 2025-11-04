#ifndef TREE_H
#define TREE_H

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* createSampleTree(void);
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);

#endif
