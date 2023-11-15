#include "main.h"

vector<string> split(string input) {
    vector<string> output = {};
    int i = 0;
    while(i < input.length()) {
        int tokenEnd = input.find(" ", i);
        string token = input.substr(i, tokenEnd - i);
        output.push_back(token);
        i += token.length() + 1;
    }
    return output;
}

string infixToPostfix(string input) {
    stack<string> opstack;
    unordered_map<string, int> prec = {
        {"*", 3},
        {"/", 3},
        {"+", 2},
        {"-", 2},
        {"(", 1}
    };
    vector<string> tokens = split(input);
    string output = "";
    for (int i = 0; i < tokens.size(); i++) {
        string token = tokens[i];
        if (token == "(") {
            opstack.push(token);            
        } else if (token == ")") {
            string topToken = opstack.top();
            opstack.pop();
            while (topToken != "(") {
                output.append(topToken + " ");
                topToken = opstack.top();
                opstack.pop();
            }
        } else if (prec.count(token)) { // check if token is in prec
            while (!opstack.empty() && prec[opstack.top()] >= prec[token]) {
                output.append(opstack.top() + " ");
                opstack.pop();
            }
            opstack.push(token);            
        } else {
            output.append(token + " ");
        }
    }
    while (!opstack.empty()) {
        output.append(opstack.top() + " ");
        opstack.pop();
    }
    return output;
}

Tree postfixToTree(string postfix) {
    stack<Node*> nodes;
    vector<string> tokens = split(postfix);
    unordered_set<string> operators = {"+", "-", "*", "/"};
    for (int i = 0; i < tokens.size(); i++) {
        Node *newNode = new Node{tokens[i]};
        if (operators.count(newNode->data)) {
            newNode->left = nodes.top();
            nodes.pop();
            newNode->right = nodes.top();
            nodes.pop();
        }
        nodes.push(newNode);
    }
    Tree tree(nodes.top());
    return tree;

}

int main() {
    string infixString = "13 + 24 * 35 / 46";
    string postfixString = infixToPostfix(infixString);
    cout << "infix: " << infixString << endl;
    cout << "postfix: " << postfixString << endl;

    return 0;
}