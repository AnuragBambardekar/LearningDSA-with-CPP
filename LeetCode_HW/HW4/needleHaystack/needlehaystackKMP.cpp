#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Another Solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(),0);

        for(int i=1; i<needle.size();i++)
        {
            int j=lps[i-1]; // Longest Prefix Suffix

            while(j>0 && needle[j]!=needle[i])
            {
                j = lps[j-1];
            }

            if(needle[j]==needle[i])
            {
                j++;
            }
            lps[i] = j;
        }

        int n = haystack.size();
        int i=0;
        int j=0;
        int m = needle.size();
        int count = 0;
        vector<int> ans;
        while(i<n)
        {
            if(j < m && needle[j] == haystack[i])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                ans.push_back(i-m); // if we want to return starting index of matched strings
                j = lps[j-1];
            }
            else if(i<n && needle[j] != haystack[i])
            {
                if(j==0)
                {
                    i++;
                }
                else if(j>0)
                {
                    j = lps[j-1];
                }
                
            }
        }
        if(ans.empty()) {
            if(haystack.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(-1);
            }
        }
        return ans[0];
    }
};

int main() {
    // create a vector of operations
    // string haystack = "hello";
    // string needle = "ll";

    // string haystack = "";
    // string needle = "";

    string haystack = "aaaaa";
    string needle = "bba";

    // create an instance of the Solution class
    Solution s;

    int pos = s.strStr(haystack, needle);

    // output the total score
    cout << pos << endl;

    return 0;
}