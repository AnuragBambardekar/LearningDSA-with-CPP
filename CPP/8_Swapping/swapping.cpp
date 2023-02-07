#include <iostream>
using namespace std;

int main()
{
    cout<<"Swapping Program"<<endl;
    int x=5, y=6, temp;
    cout<<"Before Swapping: "<<endl;
    cout<<"x= "<<x<<endl;
    cout<<"y= "<<y<<endl;

    //Swapping
    temp = x;
    x = y;
    y = temp;

    cout<<"After Swapping: "<<endl;
    cout<<"x= "<<x<<endl;
    cout<<"y= "<<y<<endl;
}