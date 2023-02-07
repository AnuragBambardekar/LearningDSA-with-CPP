#include <iostream>
using namespace std;
int main()
{
    int x, fact;
    cout<<"Enter a number to calculate its factorial: "<<endl;
    cin>>x;
    fact = x;

    while(x > 1){
        x--;
        fact = fact * x;
    }

    cout<<"Factorial is: "<<fact;

    return 0;
}