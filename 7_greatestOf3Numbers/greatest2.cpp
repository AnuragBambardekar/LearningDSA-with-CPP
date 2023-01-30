#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter 3 integers: "<<endl;
    int x,y,z;
    cin>>x>>y>>z;

    if((x>y) && (x>z)){
        cout<<x<<" is the greatest number.";
    }
    
    else if((y>x) && (y>z)){
        cout<<y<<" is the greatest number.";
    }

    else{
        cout<<z<<" is the greatest number.";
    }

    return 0;
}