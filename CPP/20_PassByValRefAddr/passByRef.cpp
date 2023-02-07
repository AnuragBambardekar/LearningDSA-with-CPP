#include <iostream>
using namespace std;

//call by value or pass by value
void passByReference(int &x, int &y)
{
    //swapping
    int z = x;
    x = y;
    y = z;
}

int main()
{
    int a=5, b=6;
    cout<<"Before swapping: "<<endl<<"a: "<<a<<endl<<"b: "<<b<<endl;

    //call function
    //a and b values are altered, since x and y are alias names
    //to the memory locations of a and b respectively.
    //no need to create a copy of the variables
    passByReference(a,b);

    cout<<"After swapping: "<<endl<<"a: "<<a<<endl<<"b: "<<b<<endl;
    return 0;
}