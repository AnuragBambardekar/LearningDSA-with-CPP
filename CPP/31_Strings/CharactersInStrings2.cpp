#include <iostream>
#include <string>
using namespace std;
int main()
{
    string readMe ("hello There");
    if(!readMe.empty())
        cout<<readMe[0]<<endl;

    //capitalize first letter
    if(!readMe.empty())
        readMe[0] = toupper(readMe[0]);
    cout<<readMe<<endl;

    //capitalize first word
    decltype(readMe.size()) i;
    for(int i =0; i!=readMe.size() && !isspace(readMe[i]); i++)
        readMe[i] = toupper(readMe[i]);
    cout<<readMe<<endl;

    //generate hexadecimal representation from decimal
    const string hexdigits = "0123456789ABCDEF";
    cout<<"Enter a string of 0-15 numbers, separated by spaces."<<endl;
    string result;
    string::size_type ip;

    while(cin>>ip)
    if(ip<hexdigits.size())
    result += hexdigits[ip];
    cout<<"Your hex number is: "<<result<<endl;

    /**
     * 12 10 15 14
       ^Z
       Your hex number is: CAFE
    */

    return 0;
}