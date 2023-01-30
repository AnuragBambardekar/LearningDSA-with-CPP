#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter a number: ";
    int x;
    cin>>x;
    
    if(x<0)
    {
        cout<<"x: "<<x<<" is negative.\n";
    }
    else if(x>0)
    {
        cout<<"x: "<<x<<" is positive.\n";
    }
    else
    {
        cout<<"Value of x: "<<x<<"\n";
    }

}