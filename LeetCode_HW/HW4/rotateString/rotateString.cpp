#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
    if(s.size() != goal.size())
        return false;
        if(s == goal)      //for empty strings
            return true;
        
        int len = goal.size();
        while(len--)
        {
            if(s == goal)
                return true;
            s = s.substr(1) + s[0];     // one shift on s
        }
        return false;
    }
};


int main() {
    string str1, str2;
    str1 = "abcde";
    str2 = "abced";
    
    Solution sol;

    if (sol.rotateString(str1, str2)) {
        cout << str1 << " and " << str2 << " are rotations of each other." << endl;
    } else {
        cout << str1 << " and " << str2 << " are not rotations of each other." << endl;
    }
    
    return 0;
}
