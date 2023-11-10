#include "main.h"

string infixToPostfix(string input) {
    stack<string> opstack;
    int i = 0;
    string output = "";
    while(i < input.length()) {
        int tokenEnd = input.find(" ", i);
        string token = input.substr(i, tokenEnd - i);
        
        cout << token << endl;
        i += token.length() + 1;
    }
    return output;
}

int main() {
    string infixString = "-13 + 24 * -35 / 46";
    string postfixString = infixToPostfix(infixString);
    cout << "infix: " << infixString << endl;
    cout << "postfix: " << postfixString << endl;

    return 0;
}