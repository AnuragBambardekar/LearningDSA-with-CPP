#include <iostream>
#include <stack>
#include <string>

// Manual process by paranthesizing the expression

using namespace std;

// function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// function to check the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

// function to convert infix expression to postfix notation
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // if current character is an operand, add it to postfix
        if (isalnum(c)) {
            postfix += c;
        }
        // if current character is an operator
        else if (isOperator(c)) {
            // pop all operators with higher or equal precedence from stack
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(c)) {
                postfix += s.top();
                s.pop();
            }
            // push the current operator to stack
            s.push(c);
        }
        // if current character is a left parenthesis, push it to stack
        else if (c == '(') {
            s.push(c);
        }
        // if current character is a right parenthesis, pop operators from stack
        // until the corresponding left parenthesis is found
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
        }
    }

    // pop any remaining operators from stack and add them to postfix
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix = "A/(B+C)-D";
    string temp = "(" + infix + ")";
    string parenthesized = "";
    stack<char> s;

    // Step (a): fully parenthesize the infix expression
    for (int i = 0; i < temp.length(); i++) {
        char c = temp[i];

        if (isalnum(c)) {
            parenthesized += c;
        }
        else if (isOperator(c)) {
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(c)) {
                parenthesized += s.top();
                s.pop();
            }
            s.push(c);
            parenthesized += " ";
        }
        else if (c == '(') {
            s.push(c);
            parenthesized += c;
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                parenthesized += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
            parenthesized += c;
        }
    }

    // Step (b): replace right parentheses with their corresponding operators
    string replaced = "";
    for (int i = 0; i < parenthesized.length(); i++) {
        char c = parenthesized[i];

        if (c == '(') {
            continue;
        }
        else if (isOperator(c)) {
            replaced += c;
            replaced += parenthesized[i + 1];
            i++;
        }
        else {
            replaced += c;
        }
    }

    // Step (c): remove left parentheses
    string postfix = infixToPostfix(replaced);

    cout << "Infix: " << infix << endl;
    cout << "Paranthesized: "<<parenthesized<<"\n";
    // cout<<replaced<<"\n";
    cout << "Postfix: " << postfix << endl;

    return 0;
}
