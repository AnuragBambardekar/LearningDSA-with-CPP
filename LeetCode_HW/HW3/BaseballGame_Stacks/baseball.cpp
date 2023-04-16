#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string  i:ops)
        {
            if(i=="C"){ st.pop();}
            else if(i=="D"){ st.push(st.top()*2);}
            else if(i=="+"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.push(v1);
                st.push(v1+v2);
            }
            else {
                st.push(stoi(i));
            }
        }
        // return sum of elements in stack
        int res=0;
        while(st.size()!=0){
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main() {
    // create a vector of operations
    vector<string> ops = {"5", "2", "C", "D", "+"};

    // create an instance of the Solution class
    Solution s;

    // call the calPoints() function to calculate the total score
    int score = s.calPoints(ops);

    // output the total score
    cout << "Total score: " << score << endl;

    return 0;
}