#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Reverse Polish Notation Algorithm to evaluate Postfix expressions

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

string infixToPostfix(string expression) {
    stack<char> operatorStack;
    string postfix = "";
    expression = "(" + expression + ")";
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();
            }
        } else if (!isOperator(c)) {
            postfix += c;
        } else {
            while (!operatorStack.empty() && precedence(c) <= precedence(operatorStack.top())) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }
    return postfix;
}

int main() {
    // string expression = "a+b*c/(d-e)";
    string expression = "A+(B*C-(D/E^F)*G)*H";
    cout << "Infix expression: " << expression << endl;
    string postfix = infixToPostfix(expression);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
