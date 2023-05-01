#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        int x=0, y=0;
        vector<int> dp(n+1,0);
        if(s[0]=='a')
            x++;
        else
            y++;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='a' && y!=0)
            {
                dp[i] = min(dp[i-1]+1, min(y,x+1));
            }
            else
                dp[i] = dp[i-1];
            if(s[i]=='a')
                x++;
            else
                y++;
        }
        return dp[n-1];
    }
};

int main() {
    Solution sol;
    std::string s1 = "aababbab";
    std::string s2 = "bbaaaaabb";
    std::cout << "s1: " << sol.minimumDeletions(s1) << std::endl;
    std::cout << "s2: " << sol.minimumDeletions(s2) << std::endl;
    return 0;
}