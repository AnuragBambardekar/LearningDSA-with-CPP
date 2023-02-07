#include <iostream>
using namespace std;

int sum(int a, int b, int c=0, int d=5) //rightmost value has to be default
{
    //c and d are default parameters
    return (a+b+c+d);
}

int main()
{
    //overrides the default params
    cout<<"Sum of 1,2,3,4 is: "<<sum(1,2,3,4)<<endl;
    //uses the default params
    cout<<"Sum of 1,2, and default params is: "<<sum(1,2);
    return 0;
}