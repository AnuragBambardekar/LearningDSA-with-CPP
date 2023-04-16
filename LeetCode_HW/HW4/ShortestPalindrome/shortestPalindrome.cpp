#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kmp(string str)
    {
        vector<int> lps(str.size(), 0);
        int i=1,j=0;
    
        while(i < str.size())
        {
            if(str[i] == str[j])
            {
                lps[i] = j + 1;
                j++;
                i++;
            }
            else
            {
                if(j == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                {
                    j = lps[j - 1];
                }
            }
        }
        return lps[str.size() - 1];
    }
    string shortestPalindrome(string s) {
        int n = s.size();
        // string rev = s;
        // reverse(rev.begin(), rev.end());
        string rev = "";
        for(int i=n-1;i>=0;i--)
        {
            rev += s[i];
        }
        
        int lps = kmp(s + "#" + rev);
        
        string append = s.substr(lps);
        // reverse(append.begin(), append.end());
        string res = "";
        for(int i=append.size()-1;i>=0;i--)
        {
            res += append[i];
        }
        
        // return append + s;
        return res + s;
    }
};


int main() {
    Solution sol;
    string s = "abcd";
    cout << "Shortest palindrome of " << s << " is: " << sol.shortestPalindrome(s) << endl;

    s = "aacecaaa";
    cout << "Shortest palindrome of " << s << " is: " << sol.shortestPalindrome(s) << endl;

    s = "abbacd";
    cout << "Shortest palindrome of " << s << " is: " << sol.shortestPalindrome(s) << endl;

    return 0;
}