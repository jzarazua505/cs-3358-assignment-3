#include "tree.h"

Tree::Tree(Node* initRoot) {
    root = initRoot;
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

void Tree::toInfix(Node *currentNode, string &output) {
    if (currentNode->left) {
        output.append("( ");
        toInfix(currentNode->left, output);
    }
    output.append(currentNode->data + " ");
    if (currentNode->right) {
        toInfix(currentNode->right, output);
        output.append(") ");
    }
}

string Tree::toInfix() {
    string output;
    toInfix(root, output);
    output.pop_back();
    return output;
}

void Tree::toPrefix(Node *currentNode, string &output) {

}

string Tree::toPrefix() {
    return "";
}

void Tree::toPostfix(Node *currentNode, string &output) {

}

string Tree::toPostfix() {
    return "";
}
