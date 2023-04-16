#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string helper(string s, int& pos)
{
    string word = "";
    int num=0;
    while(pos<s.size()) //loop over the string
    {
        if(s[pos] == '[') // if '[' is found in string, get the repeating string
        {
            pos++; // next character index
            string myString = helper(s, pos); // recursion

            for(int i=0;i<num;i++)
            {
                word+=myString;
            }
            num=0;
        }
        else if (s[pos] == ']')
        {
            return word;
        }
        else if (isdigit(s[pos]))
        {
            num = num*10 + s[pos]-'0';
        }
        else
        {
            word += s[pos];
        }
        pos++;
    }
    return word;
}

class Solution {
public:
    string decodeString(string s)  {
        int pos=0;
        return helper(s,pos);
    }
};

int main() {
    // create a vector of operations
    // string ops = "3[a]2[bc]";
    // string ops = "3[a2[c]]";
    string ops = "2[abc]10[cd]ef";

    // create an instance of the Solution class
    Solution s;

    // call the calPoints() function to calculate the total score
    string res = s.decodeString(ops);

    // output the total score
    cout << res << endl;

    return 0;
}