#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count = 0;
        for(char i:s)
        {
            if(i=='('){
                if(count>0)
                {
                    res += i;
                }
                count++;
            }
            else {
                if(count>1)
                {
                    res += i;
                }
                count--;
            }
        }   
        return res; 
    }
};

int main() {
    Solution sol;
    std::string s1 = "(()())(())";
    std::cout << "Input: " << s1 << std::endl;
    std::cout << "Output: " << sol.removeOuterParentheses(s1) << std::endl;

    std::string s2 = "()()()()";
    std::cout << "Input: " << s2 << std::endl;
    std::cout << "Output: " << sol.removeOuterParentheses(s2) << std::endl;

    std::string s3 = "(((())))";
    std::cout << "Input: " << s3 << std::endl;
    std::cout << "Output: " << sol.removeOuterParentheses(s3) << std::endl;

    return 0;
}