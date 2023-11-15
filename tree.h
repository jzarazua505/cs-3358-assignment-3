#ifndef TREE_H
#define TREE_H

#include <string>

using std::string; 

struct Node {
    string data;
    Node *left;
    Node *right;
};

class Tree
{
private:
    Node *root;
    void deleteNode(Node*);

public:
    Tree();
    ~Tree();
    float evaluate();

};



#endif