#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(string expression) {
    string result = "";
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];

        if (isalnum(current)) {
            result += current;
        } else if (current == '(') {
            operators.push(current);
        } else if (current == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result += operators.top();
                operators.pop();
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
        } else {
            while (!operators.empty() && precedence(current) <= precedence(operators.top())) {
                result += operators.top();
                operators.pop();
            }
            operators.push(current);
        }
    }

    while (!operators.empty()) {
        result += operators.top();
        operators.pop();
    }

    return result;
}

int evaluatePostfix(string expression) {
    stack<int> operands;

    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];

        if (isdigit(current)) {
            operands.push(current - '0');
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (current) {
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
                    operands.push(operand1 / operand2);
                    break;
                case '^':
                    operands.push(pow(operand1, operand2));
                    break;
            }
        }
    }

    return operands.top();
}

int main() {
    vector<string> expressions = {"3+4*2/(1-5)^2", "5*(7-2)/3+8",
                                  "9*8/4-2+6/3+1", "(4+5)*2-8/4+9",
                                  "6*7-4/2+3*(8-5)","(2+3*4)10&6|4^2"};
    for (auto& expression : expressions) {
        cout << "Infix Expression: " << expression << endl;
        string postfixExpression = infixToPostfix(expression);
        cout << "Postfix Expression: " << postfixExpression << endl;
        int result = evaluatePostfix(postfixExpression);
        cout << "Result: " << result << endl;
        cout << endl;
    }
    return 0;
}

