#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        long long res = 0, operand = 0, sign = 1;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                operand = operand * 10 + s[i] - '0';
            } else if (s[i] == '+') {
                res += sign * operand;
                operand = 0;
                sign = 1;
            } else if (s[i] == '-') {
                res += sign * operand;
                operand = 0;
                sign = -1;
            } else if (s[i] == '(') {
                stack.push(res);
                stack.push(sign);
                res = operand = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res = stack.top() * (res + sign * operand);
                stack.pop();
                res += stack.top();
                stack.pop();
                operand = 0;
                sign = 1;
            }
        }
        return res + operand * sign;
    }
};

int main() {
    // string ops = "1+1";
    // string ops = "2-1+2";
    string ops = "( 1 +(40+6 +2 )-3)+(6+8)";
    
    // create an instance of the Solution class
    Solution s;

    // call the calPoints() function to calculate the total score
    int res = s.calculate(ops);

    // output the total score
    cout << res << endl;

    return 0;
}