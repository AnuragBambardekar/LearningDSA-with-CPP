#include <iostream>
using namespace std;

int main()
{
    int ival = 50;
    int *p = &ival;
    cout<<ival<<endl<<p<<endl<<*p<<endl<<"\n";

    *p = 51;
    cout<<ival<<endl<<p<<endl<<*p<<endl<<"\n";

    ival = 52;
    cout<<ival<<endl<<p<<endl<<*p<<endl<<"\n";

    return 0;
}