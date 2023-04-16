#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> kmp(string text, string pattern){
        vector<int> lps(pattern.size(),0);

        for(int i=1; i<pattern.size();i++)
        {
            int j=lps[i-1]; // Longest Prefix Suffix

            while(j>0 && pattern[j]!=pattern[i])
            {
                j = lps[j-1];
            }

            if(pattern[j]==pattern[i])
            {
                j++;
            }
            lps[i] = j;
        }

        // Iterator Method
        int n = text.size();
        int i=0;
        int j=0;
        int m = pattern.size();
        int count = 0;
        vector<int> ans;
        vector<int> counts;
        while(i<n)
        {
            if(j < m && pattern[j] == text[i])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                count++; 
                ans.push_back(i-m); // if we want to return starting index of matched strings
                j = lps[j-1];
            }
            else if(i<n && pattern[j] != text[i])
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
        if(ans.empty())
        {
            if(count==0)
            {
                ans.push_back(-1);
            }
        }
        else if(count>0)
        {
            ans.push_back(count); // if we want to return count of matched strings
        }
        return ans;
    }
};

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    // string text = "batmanandrobinarebat";
    // string pattern = "bat";
    // string text = "abesdu";
    // string pattern = "edu";

    Solution s;
    vector<int> result = s.kmp(text, pattern);

    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

// Test Cases:
// text = "batmanandrobinarebat"
// pattern = "bat"
// output: 1 18
// string "bat" occurs twice starting at index 1 and index 18