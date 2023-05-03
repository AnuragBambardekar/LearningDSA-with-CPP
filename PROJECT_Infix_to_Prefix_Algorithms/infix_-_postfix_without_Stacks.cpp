#include <iostream>
#include <string>
#include <stack> // only for evaluating & checking validity of expression and not conversion
#include <cmath>
#include <vector>

// Without Using Stacks

using namespace std;

int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } 
    return 0;
    
}

bool isBalanced(string expression) {
    stack<char> parentheses;

    for (int i = 0; i < expression.length(); i++) {
        char token = expression[i];

        if (token == '(') {
            parentheses.push(token);
        } else if (token == ')') {
            if (parentheses.empty() || parentheses.top() != '(') {
                return false;
            } else {
                parentheses.pop();
            }
        }
    }

    return parentheses.empty();
}

string infixToPostfix(string infix) {
    string postfix = "";
    string operators = "";

    if (!isBalanced(infix)) {
        throw invalid_argument("unbalanced parentheses");
    }

    for (int i = 0; i < infix.length(); i++) {
        char token = infix[i];

        if (isdigit(token) || isalpha(token)) {
            postfix += token;
        } else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^') {
            while (!operators.empty() && precedence(operators.back()) >= precedence(token)) {
                postfix += operators.back();
                operators.pop_back();
            }
            operators += token;
        } else if (token == '(') {
            operators += token;
        } else if (token == ')') {
            while (operators.back() != '(') {
                postfix += operators.back();
                operators.pop_back();
            }
            operators.pop_back();
        }
    }

    while (!operators.empty()) {
        postfix += operators.back();
        operators.pop_back();
    }

    return postfix;
}

int evaluatePostfix(string expression) {
    stack<int> operands;

    for (int i = 0; i < expression.length(); i++) {
        char token = expression[i];

        if (isdigit(token)) {
            operands.push(token - '0');
        } else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^') {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (token) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        throw invalid_argument("division by zero");
                    }
                    operands.push(operand1 / operand2);
                    break;
                case '^':
                    operands.push(pow(operand1, operand2));
                    break;
            }
        }
    }

    if (operands.size() != 1) {
        throw invalid_argument("invalid expression");
    }

    return operands.top();
}


int main() {
    vector<string> expressions = {"3+4*2/(1-5)^2", "5*(7-2)/3+8",
                                  "9*8/4-2+6/3+1", "(4+5)*2-8/4+9",
                                  "6*7-4/2+3*(8-5)","(2+3*4)10&6|4^2",
                                  "((6+4)-2","1+(2*3-(4/5^6)*7)*8"};
    for (auto& expression : expressions) {
    cout << "Infix Expression: " << expression << endl;
    try {
        string postfixExpression = infixToPostfix(expression);
        cout << "Postfix Expression: " << postfixExpression << endl;
        int result = evaluatePostfix(postfixExpression);
        cout << "Result: " << result << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;
}

    return 0;
}
