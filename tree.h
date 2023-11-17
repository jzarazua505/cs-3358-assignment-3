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
    void toInfix(Node*, string&);
    void toPrefix(Node*, string&);
    void toPostfix(Node*, string&);

public:
    Tree(Node*);
    ~Tree();
    string toInfix();
    string toPrefix();
    string toPostfix();

};

#endif