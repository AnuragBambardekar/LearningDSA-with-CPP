#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1,q2;

        for(int i=0; i<s.size();i++)
        {
            q1.push(s[i]);
        }
        for(int i=0; i<goal.size();i++)
        {
            q2.push(goal[i]);
        }
        int k = goal.size()-1;
        while(k!=0)
        {
            char ch = q2.front();
            q2.pop();
            q2.push(ch);

            if(q1==q2) return true;

            k--;
        }
        return false;
    }
};


int main() {
    string str1, str2;
    // str1 = "abcde";
    // str2 = "abced";

    // str1 = "abcde";
    // str2 = "cdeab";

    str1 = "bcgefm";
    str2 = "efmbcg";
    
    Solution sol;

    if (sol.rotateString(str1, str2)) {
        cout << str1 << " and " << str2 << " are rotations of each other." << endl;
    } else {
        cout << str1 << " and " << str2 << " are not rotations of each other." << endl;
    }
    
    return 0;
}
