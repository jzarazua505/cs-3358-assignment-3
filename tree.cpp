#include "tree.h"

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    deleteNode(root);
}

void Tree::deleteNode(Node *node) {
    if (node->left) {
        deleteNode(node->left);
    }
    if (node->right) {
        deleteNode(node->right);
    }
    delete node;
}
