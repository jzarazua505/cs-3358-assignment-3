#include "main.h"

string infixToPostfix(string input) {
    stack<string> opstack;
    unordered_map<string, int> prec = {
        {"*", 3},
        {"/", 3},
        {"+", 2},
        {"-", 2},
        {"(", 1}
    };
    int i = 0;
    string output = "";
    while(i < input.length()) {
        int tokenEnd = input.find(" ", i);
        string token = input.substr(i, tokenEnd - i);
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
        i += token.length() + 1;
    }
    while (!opstack.empty()) {
        output.append(opstack.top() + " ");
        opstack.pop();
    }
    return output;
}

int main() {
    string infixString = "( ( ( ( 1 * ( 2 + 3 ) ) - 3 ) + 4 ) * 5 )";
    string postfixString = infixToPostfix(infixString);
    cout << "infix: " << infixString << endl;
    cout << "postfix: " << postfixString << endl;

    return 0;
}