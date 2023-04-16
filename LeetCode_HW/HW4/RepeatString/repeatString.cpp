#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Bruteforce Solution
class Solution {
public:
    bool check(string &a, string &b)
    {
        int m=a.size();
        int n=b.size();
        
        for(int i=0;i<=m-n;i++)
        {
            int j;
            for(j=0;j<n;j++){
                if(a[i+j]!=b[j])
                    break;
            }
            if(j==n)
                return true;
        }
        return false;
    }
    
    // Bruteforce Solution
    int repeatedStringMatch(string a, string b) 
    {
        int m=a.size();
        int n=b.size();
        
        int ans=1;
        string tmp=a;
        while(a.size() < b.size()){
            a += tmp;
            ans++;
        }
        
        if(check(a,b)){
            return ans;
        }
        a += tmp;
        if(check(a,b)){
            return ans+1;
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

    string a = "abcd";
    string b = "cdabcdab";

    // create an instance of the Solution class
    Solution s;

    int pos = s.repeatedStringMatch(a, b);

    // output the total score
    cout << pos << endl;

    return 0;
}