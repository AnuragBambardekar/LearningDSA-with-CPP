#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        if (s.empty()) {
            return true;
        }
        
        // Concatenate s with itself
        string s2 = s + s;
        
        // Use KMP to find goal in s2
        vector<int> lps = computeLPS(goal);
        int n = s2.size(), m = goal.size(), j = 0;
        for (int i = 0; i < n; i++) {
            while (j > 0 && s2[i] != goal[j]) {
                j = lps[j-1];
            }
            if (s2[i] == goal[j]) {
                j++;
            }
            if (j == m) {
                return true;
            }
        }
        
        return false;
    }

    // Compute the KMP prefix table for a pattern
    vector<int> computeLPS(string pattern) {
        int n = pattern.size();
        vector<int> lps(n);
        int len = 0;
        lps[0] = 0;
        for (int i = 1; i < n; i++) {
            while (len > 0 && pattern[len] != pattern[i]) {
                len = lps[len-1];
            }
            if (pattern[len] == pattern[i]) {
                len++;
            }
            lps[i] = len;
        }
        return lps;
    }
};



int main() {
    string str1, str2;
    // str1 = "abcde";
    // str2 = "abced";

    // str1 = "abcde";
    // str2 = "cdeab";

    // str1 = "bcgefm";
    // str2 = "efmbcg";

    str1 = "bcgefm";
    str2 = "fmbcge";
    
    Solution sol;

    if (sol.rotateString(str1, str2)) {
        cout << str1 << " and " << str2 << " are rotations of each other." << endl;
    } else {
        cout << str1 << " and " << str2 << " are not rotations of each other." << endl;
    }
    
    return 0;
}
