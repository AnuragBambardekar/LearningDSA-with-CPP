#include <iostream>
using namespace std;

//References to const
int main()
{
    const int ci = 1024;
    const int &r1 = ci;
    cout<<r1<<endl;
    //const int &r1 = 2048;
    //cout<<r1<<endl;

    //r1 = 42; //ERROR
    //int &r2 = ci; //ERROR

    //we can bind a reference to const to a non const object, a literal or a more general expression
    int i = 42;
    const int &r = i;
    cout<<r<<endl;
    const int &r2 = 42; //this binding to literals was not possible with non- "const" references
    cout<<r2<<endl;
    const int &r3 = r1*2; //can also bind general expressions
    cout<<r3<<endl;

    //Now, how is references to const legal like this?
    /**
     * double dval = 3.14;
     * const int &ri = dval;
     * 
     * above 2 lines, compiler transforms this code to:
     * int temp = dval;
     * const int &ri = temp;
    */

    //int &r4 = r1*2; //ERROR

}