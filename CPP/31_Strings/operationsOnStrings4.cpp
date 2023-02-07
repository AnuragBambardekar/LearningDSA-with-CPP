#include <iostream>
#include <string>
using namespace std;
int main()
{
    //Assignment
    string readMe = "Hello";
    string copyHere = readMe;
    string eS (3, 'E');

    //Adding Strings
    string s1 = "Hello,";
    string s2 = " There";
    string res = s1 + s2;
    cout<<res<<endl;

    //Adding Literals and strings
    string s4 = "Try ", s5 = " New";
    string s6 = s4 + " Something " + s5;
    string s7 = s6 + " Everyday";

    cout<<s7;

    //string s8 = "Try" + "Something"; //ERROR!
    //string s9 = "Try" + "Something" + s2; //ERROR!


    return 0;
}