#include <iostream>
using namespace std;
int main()
{
    int a[3];
    int b[3];
    int add[3], sub[3], mul[3];

    cout<<"Enter 3 integers: "<<endl;
    for(int i = 0; i<3; i++)
    {
        cin>>a[i];
    }
    cout<<"Enter 3 integers: "<<endl;
    for(int i = 0; i<3; i++)
    {
        cin>>b[i];
    }
    cout<<"Addition of Array values: "<<endl;
    for(int i = 0; i<3; i++)
    {
        add[i]=a[i]+b[i];
        cout<<add[i]<<endl;
    }
    cout<<"Subtraction of Array values: "<<endl;
    for(int i = 0; i<3; i++)
    {
        sub[i]=a[i]-b[i];
        cout<<sub[i]<<endl;
    }
    
}