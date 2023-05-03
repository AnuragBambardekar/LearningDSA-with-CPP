#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> opStack;
    queue<char> outputQueue;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        
        if (isalnum(ch)) { // If operand, enqueue
            outputQueue.push(ch);
        } else if (ch == '(') { // If left parenthesis, push to stack
            opStack.push(ch);
        } else if (ch == ')') { // If right parenthesis, pop from stack until left parenthesis
            while (!opStack.empty() && opStack.top() != '(') {
                outputQueue.push(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty())
                opStack.pop(); // Remove the left parenthesis from the stack
        } else { // If operator, handle precedence
            while (!opStack.empty() && getPrecedence(ch) <= getPrecedence(opStack.top())) {
                outputQueue.push(opStack.top());
                opStack.pop();
            }
            opStack.push(ch); // Push the current operator to the stack
        }
    }
    
    // Enqueue any remaining operators from the stack
    while (!opStack.empty()) {
        outputQueue.push(opStack.top());
        opStack.pop();
    }
    
    // Concatenate the queue elements to form the postfix expression
    while (!outputQueue.empty()) {
        postfix += outputQueue.front();
        outputQueue.pop();
    }
    
    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
