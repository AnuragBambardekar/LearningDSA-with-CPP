#include <iostream>
using namespace std;
int main()
{
    int num, x=0,y=1,z;
    cout<<"Enter a positive integer (total number of terms): ";
    cin>>num;

    cout<<"Fibonacci Series: ";
    for(int i = 0; i<num; i++){
        cout<< x + y<<"  ";
        z=x+y;
        x=y;
        y=z;
    }
}