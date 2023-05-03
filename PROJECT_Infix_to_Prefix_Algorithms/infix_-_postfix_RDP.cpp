#include <iostream>
#include <string>
#include <stack>

// Recursive Descent Parsing
using namespace std;

// Function to check if a given character is an operator or not
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to check if a given character is an operand or not
bool isOperand(char c) {
    return (c >= '0' && c <= '9');
}

// Function to perform the operation
int performOperation(char operation, int operand1, int operand2) {
    if (operation == '+') {
        return operand1 + operand2;
    }
    else if (operation == '-') {
        return operand1 - operand2;
    }
    else if (operation == '*') {
        return operand1 * operand2;
    }
    else if (operation == '/') {
        return operand1 / operand2;
    }
    else {
        return 0;
    }
}

// Recursive function to convert the expression to postfix notation
string convertToPostfix(string expression, int& i) {
    stack<char> s;
    string postfix = "";
    while (i < expression.length()) {
        char c = expression[i];
        if (isOperand(c)) {
            postfix += c;
        }
        else if (isOperator(c)) {
            while (!s.empty() && s.top() != '(' && ((c != '*' && c != '/') || (s.top() != '+' && s.top() != '-'))) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == '(') {
            s.push(c);
            postfix += convertToPostfix(expression, ++i);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
            return postfix;
        }
        i++;
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isOperand(c)) {
            s.push(c - '0');
        }
        else if (isOperator(c)) {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            int result = performOperation(c, operand1, operand2);
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string expression;
    cout << "Enter the expression: ";
    getline(cin, expression);
    int i = 0;
    string postfix = convertToPostfix(expression, i);
    cout << "Postfix notation: " << postfix << endl;
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}
