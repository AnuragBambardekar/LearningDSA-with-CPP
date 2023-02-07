#include <iostream>
using namespace std;

int main()
{
    int ival = 1024;
    int &refVal = ival;
    //int &refVal2; //error

    cout<<ival<<endl<<refVal<<endl;
    refVal = 100;
    cout<<ival<<endl<<refVal<<endl;

    return 0;
}