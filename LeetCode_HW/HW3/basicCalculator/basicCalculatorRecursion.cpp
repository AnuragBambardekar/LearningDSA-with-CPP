#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int i=0;
        return solve(i,s,s.size());
    }
    int solve(int &i,string &s,int n){
        int ans=0;
        int j=i;
        int minus=false;

        while(i<n && s[i]!=')'){
            int num=0;
            while(i<n && s[i]>='0' && s[i]<='9'){   
                num=num*10+(s[i]-'0'); // get the number
                i++;
            }
            if(s[i]=='('){
                i++; // next element (number)
                num=solve(i,s,n);
                i++;
            }

            ans+=(minus?-num:num);
            if(s[i]==')')   break;
            if(i<n && s[i]=='-')   
                minus=true;
            if(i<n && s[i]=='+')   
                minus=false;
            i++;
        }
        return ans;        
    }
};

int main() {
    // string ops = "1+1";
    // string ops = "2-1+2";
    string ops = "( 1 +(4+6 +2 )-3)+(6+8)";
    
    // create an instance of the Solution class
    Solution s;

    // call the calPoints() function to calculate the total score
    int res = s.calculate(ops);

    // output the total score
    cout << res << endl;

    return 0;
}