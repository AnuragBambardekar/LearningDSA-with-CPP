#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Visualize step by step how Postfix expressions are evaluated

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

string infixToPostfix(string infix) {
    string postfix = "";
    stack<char> operators;
    for(char c : infix) {
        if(isalnum(c)) {
            postfix += c;
        } else if(c == '(') {
            operators.push(c);
        } else if(c == ')') {
            while(!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if(!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
        } else {
            while(!operators.empty() && precedence(c) <= precedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
        cout << "Current postfix expression: " << postfix << endl;
        cout << "Current operator stack: ";
        stack<char> temp = operators;
        while(!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl << endl;
    }
    while(!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
