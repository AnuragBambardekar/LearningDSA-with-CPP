#include <iostream>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

void displayMenu() {
    cout << "Enter an arithmetic expression, or enter 'q' to quit." << endl;
}

void add(stack<double>& operands) {
    double op2 = operands.top();
    operands.pop();
    double op1 = operands.top();
    operands.pop();
    operands.push(op1 + op2);
}

void subtract(stack<double>& operands) {
    double op2 = operands.top();
    operands.pop();
    double op1 = operands.top();
    operands.pop();
    operands.push(op1 - op2);
}

void multiply(stack<double>& operands) {
    double op2 = operands.top();
    operands.pop();
    double op1 = operands.top();
    operands.pop();
    operands.push(op1 * op2);
}

void divide(stack<double>& operands) {
    double op2 = operands.top();
    operands.pop();
    double op1 = operands.top();
    operands.pop();
    if (op2 != 0) {
        operands.push(op1 / op2);
    } else {
        cout << "Error: Division by zero" << endl;
    }
}

void modulo(stack<double>& operands) {
    double op2 = operands.top();
    operands.pop();
    double op1 = operands.top();
    operands.pop();
    operands.push(fmod(op1, op2));
}


void sqrt(stack<double>& operands) {
    double op = operands.top();
    operands.pop();
    if (op >= 0) {
        operands.push(std::sqrt(op));
    } else {
        cout << "Error: Square root of negative number" << endl;
    }
}

void exponentiate(stack<double>& operands) {
    double op2 = operands.top();
    operands.pop();
    double op1 = operands.top();
    operands.pop();
    operands.push(std::pow(op1, op2));
}

void factorial(stack<double>& operands) {
    int op = static_cast<int>(operands.top());
    operands.pop();
    int result = 1;
    for (int i = 2; i <= op; i++) {
        result *= i;
    }
    operands.push(result);
}

void logarithm(stack<double>& operands) {
    double op2 = operands.top();
    operands.pop();
    double op1 = operands.top();
    operands.pop();
    if (op1 > 0 && op1 != 1 && op2 > 0) {
        operands.push(std::log(op2) / std::log(op1));
    } else {
        cout << "Error: Invalid logarithm arguments" << endl;
    }
}

void ln(stack<double>& operands) {
    double op = operands.top();
    operands.pop();
    if (op > 0) {
        operands.push(std::log(op));
    } else {
        cout << "Error: Natural logarithm of non-positive number" << endl;
    }
}

void sine(stack<double>& operands) {
    double op = operands.top();
    operands.pop();
    operands.push(std::sin(op));
}

void cosine(stack<double>& operands) {
    double op = operands.top();
    operands.pop();
    operands.push(std::cos(op));
}

void tangent(stack<double>& operands) {
    double op = operands.top();
    operands.pop();
    operands.push(std::tan(op));
}

void log10(stack<double>& operands) {
    double op = operands.top();
    operands.pop();
    if (op > 0) {
        operands.push(std::log10(op));
    } else {
        cout << "Error: Logarithm base";
    }
}

void absolute(stack<double>& operands) {
    double operand = operands.top();
    operands.pop();
    if (operand < 0) {
        operand *= -1;
    }
    operands.push(operand);
}


// Evaluate Function
double evaluate(double operand1, double operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return pow(operand1, operand2);
        default:
            return 0.0;
    }
}

double parseAndEvaluate(string expression) {
    istringstream iss(expression);
    stack<double> operands;
    stack<char> operators;
    string token;
    while (iss >> token) {
        if ((isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))) {
            operands.push(stod(token));
        } else if (token == "+" || (token == "-" && !isdigit(expression[iss.tellg()])) || token == "*" || token == "/" || token == "^") {
            while (!operators.empty() && (operators.top() == '^' || ((token == "*" || token == "/") && (operators.top() == '*' || operators.top() == '/')))) {
                char op = operators.top();
                operators.pop();
                double operand2 = operands.top();
                operands.pop();
                double operand1 = operands.top();
                operands.pop();
                operands.push(evaluate(operand1, operand2, op));
            }
            operators.push(token[0]);
        } else if (token == "log") {
            logarithm(operands);
        } else if (token == "abs") {
            absolute(operands);
        } else if (token == "%") {
            modulo(operands);
        }else if (token == "sqrt") {
            sqrt(operands);
        }else if (token == "fact") {
            factorial(operands);
        }else if (token == "sin") {
            sine(operands);
        }else if (token == "cos") {
            cosine(operands);
        }else if (token == "tan") {
            tangent(operands);
        }else if (token == "log10") {
            log10(operands);
        }else if (token == "ln") {
            ln(operands);
        }
    }
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        double operand2 = operands.top();
        operands.pop();
        double operand1 = operands.top();
        operands.pop();
        operands.push(evaluate(operand1, operand2, op));
    }
    return operands.top();
}


int main() {
    string input;
    while (true) {
        cout << "Enter an arithmetic expression, or enter 'q' to quit." << endl;
        getline(cin, input);
        if (input == "q") {
            break;
        }
        double result = parseAndEvaluate(input);
        cout << "Result: " << result << endl;
    }
    return 0;
}
