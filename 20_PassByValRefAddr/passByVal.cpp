#include <iostream>
using namespace std;

//call by value or pass by value
void passByValue(int x, int y)
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
    //a and b values are not altered
    passByValue(a,b);

    cout<<"After swapping: "<<endl<<"a: "<<a<<endl<<"b: "<<b<<endl;
    return 0;
}