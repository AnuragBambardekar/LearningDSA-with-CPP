#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Another Solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        int val = needle.size();
        if(val>haystack.size())
        {
            return -1;
        }
        for(int i = 0; i<=haystack.size()-val; i++)
        {
            if(haystack.substr(i,val) == needle)
            {
                return i;
            }
        }
        return -1; // if no match
    }
};

int main() {
    // create a vector of operations
    string haystack = "hello";
    string needle = "ll";

    // string haystack = "";
    // string needle = "";

    // string haystack = "aaaaa";
    // string needle = "bba";

    // create an instance of the Solution class
    Solution s;

    int pos = s.strStr(haystack, needle);

    // output the total score
    cout << pos << endl;

    return 0;
}