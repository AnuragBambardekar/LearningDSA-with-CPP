#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Bruteforce Solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
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