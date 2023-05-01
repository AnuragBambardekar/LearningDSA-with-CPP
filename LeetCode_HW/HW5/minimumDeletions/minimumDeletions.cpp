#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int ans = INT_MAX;
        int count = 0;

        vector<int> countA(n), countB(n);
        
        
        for (int i = 0; i < n; i++) {
            countB[i] = count;
            if(s[i] == 'b') count++;
        }
        
        count = 0;
        for (int i = n-1; i >= 0; i--) {
            countA[i] = count;
            if(s[i] == 'a') count++;
        }

        for (int i = 0; i<n; i++)
        {
            ans = min(ans, countA[i] + countB[i]);
        }
        
        return ans;
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