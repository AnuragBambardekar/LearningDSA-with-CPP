#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count = 0;
        stack<char>st;

        for(char i:s)
        {
            if(i=='('){
                if(st.size()>0)
                {
                    res += i;
                }
                st.push(i);
            }
            else {
                if(st.size()>1)
                {
                    res += i;
                }
                st.pop();
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

    std::string s4 = "(()())(())(()(()))";
    std::cout << "Input: " << s4 << std::endl;
    std::cout << "Output: " << sol.removeOuterParentheses(s4) << std::endl;

    return 0;
}