#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    // returns a boolean value indicating whether b is a substring of a
    int kmp(string a, string b)
    {
        int m=a.size();
        int n=b.size();
        
        vector<int>lps(n,0);
        int len=0, i=1;
        
        while(i<n)
        {
            if(b[len]==b[i]){ 
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0) 
                {
                    len=lps[len-1];
                }
                else 
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        i=0;
        int j=0; //i and j to traverse the strings a and b

        /**
         * If the current characters in a and b match, both indices are incremented. 
         * If j reaches the end of b, then b is a substring of a, and the function returns true. 
         * If the current characters do not match, j is reset to the length of the longest proper suffix of b that is 
         * also a prefix of the substring of b up to j.
         * If such a suffix does not exist, j is incremented, and the function continues searching for a match.
        */
        while(i<m and j<n)
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
                if(j==n){ 
                    return true;
                }
            }
            else
            {
                if(j!=0)
                {
                    j = lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return false;
    }
    
    int repeatedStringMatch(string a, string b) 
    {
        if(a == b) return 1; // checks if a and b are equal. If they are, then the result is 1
        
        int count = 1; // the function initializes a counter variable count to 1 and creates a copy of a called a_temp
        string a_temp = a;
        while(a_temp.size() < b.size()){
            a_temp+=a; // appends a to a_temp until its length is at least as long as b
            count++;
        }
        
        if(a_temp == b)  // If a_temp is equal to b, then the answer is the value of count
            return count;
        
        // checks if b is a substring of a_temp using the kmp function. If it is, then the answer is the value of count
        if(kmp(a_temp,b) == 1) 
            return count;
        
        // appends a to a_temp again and checks if b is a substring of the resulting string using the kmp function. 
        // If it is, then the answer is the value of count plus 1.
        if(kmp(a_temp+a,b) == 1) 
            return count+1;
        
        // it's impossible for b to be a substring of a after repeating it
        return -1;
    }
};

int main() {
    Solution s;
    
    string a = "abcd", b = "cdabcdab";
    int result = s.repeatedStringMatch(a, b);
    cout << result << endl;  // Output: 3
    
    a = "a", b = "aa";
    result = s.repeatedStringMatch(a, b);
    cout << result << endl;  // Output: 2
    
    a = "abc", b = "cabcabca";
    result = s.repeatedStringMatch(a, b);
    cout << result << endl;  // Output: 4
    
    return 0;
}