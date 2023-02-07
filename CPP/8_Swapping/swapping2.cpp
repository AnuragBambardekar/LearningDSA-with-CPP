#include <iostream>
using namespace std;

int main()
{
    //without using 3rd variable
    cout<<"Swapping Program"<<endl;
    int x=5, y=6, temp;
    cout<<"Before Swapping: "<<endl;
    cout<<"x= "<<x<<endl;
    cout<<"y= "<<y<<endl;

    //Swapping
    x = x + y; //11
    y = x - y; //5
    x = x - y; //6

    cout<<"After Swapping: "<<endl;
    cout<<"x= "<<x<<endl;
    cout<<"y= "<<y<<endl;
}