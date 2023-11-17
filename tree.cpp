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
    if (!currentNode) {
        return;
    }
    output.append(currentNode->data + " ");
    toPrefix(currentNode->left, output);
    toPrefix(currentNode->right, output);

}

string Tree::toPrefix() {
    string output;
    toPrefix(root, output);
    output.pop_back();
    return output;
}

void Tree::toPostfix(Node *currentNode, string &output) {
    if (!currentNode) {
        return;
    }
    toPostfix(currentNode->left, output);
    toPostfix(currentNode->right, output);
    output.append(currentNode->data + " ");
}

string Tree::toPostfix() {
    string output;
    toPostfix(root, output);
    output.pop_back();
    return output;
}

float Tree::evaluate(Node *currentNode) {
    string data = currentNode->data;
    if (data != "+" && data != "-" && data != "*" && data != "/") {
        return std::stof(data);
    }
    if (data == "+") {
        return evaluate(currentNode->left) + evaluate(currentNode->right);
    }
    if (data == "-") {
        return evaluate(currentNode->left) - evaluate(currentNode->right);
    }
    if (data == "*") {
        return evaluate(currentNode->left) * evaluate(currentNode->right);
    }
    return evaluate(currentNode->left) / evaluate(currentNode->right);
}

float Tree::evaluate() {
    return evaluate(root);
}
