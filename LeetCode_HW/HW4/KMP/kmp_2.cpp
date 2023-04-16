#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> kmp(string text, string pattern){

        string total  = pattern + "#" + text;
        vector<int> lps(total.size(),0);

        for(int i=1; i<total.size();i++)
        {
            int j=lps[i-1]; // Longest Prefix Suffix

            while(j>0 && total[j]!=total[i])
            {
                j = lps[j-1];
            }

            if(total[j]==total[i])
            {
                j++;
            }
            lps[i] = j;
        }

        // combination of Rabin-Karp and KMP Method
        int m = pattern.size();
        int count = 0;
        vector<int> ans;
        for(int i=0; i<total.size();i++)
        {
            if(lps[i] == m)
            {
                count++;
                ans.push_back(i-m-(m));
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