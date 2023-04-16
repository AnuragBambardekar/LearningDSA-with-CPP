#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
    vector<int> ans(s.size(),0);
    int i=1,j=0;
    while(i<s.size())
    {
        if(s[i]==s[j])
        {
            ans[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j==0)
            {
                ans[i]=0;
                i++;
            }
            else
            {
                j = ans[j-1];
            }
        }
    }
    
    int len = ans.back();
    return s.substr(0,len);
    }
};

int main() {
    Solution sol;
    string s1 = "level";
    string s2 = "ababab";
    string s3 = "aaaaa";
    string s4 = "abcde";
    string s5 = "a";
    
    cout << sol.longestPrefix(s1) << endl; // Output: "l"
    cout << sol.longestPrefix(s2) << endl; // Output: "abab"
    cout << sol.longestPrefix(s3) << endl; // Output: "aaaa"
    cout << sol.longestPrefix(s4) << endl; // Output: ""
    cout << sol.longestPrefix(s5) << endl; // Output: ""
    
    return 0;
}