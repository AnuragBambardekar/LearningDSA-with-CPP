#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    string decodeString(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ']') {
                st.push(s[i]);
            }
            else{
                string curr_str = "";
                
                while(st.top() != '['){
                    curr_str = st.top() + curr_str ;
                    st.pop();
                }
                
                st.pop();   // for '['

                string number = "";                
                while(!st.empty() && isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                }
                int k = stoi(number); 
                
                while(k--){
                    for(int p = 0; p < curr_str.size() ; p++)
                        st.push(curr_str[p]);
                }
            }
        }
        
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
        
    }
};


int main() {
    // create a vector of operations
    // string ops = "3[a]2[bc]";
    // string ops = "3[a2[c]]";
    string ops = "12[abc]30[cd]ef";

    // create an instance of the Solution class
    Solution s;

    // call the calPoints() function to calculate the total score
    string res = s.decodeString(ops);

    // output the total score
    cout << res << endl;

    return 0;
}