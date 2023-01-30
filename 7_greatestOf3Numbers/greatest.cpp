#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter 3 integers: "<<endl;
    int x,y,z;
    cin>>x>>y>>z;

    if(x>y){
        if(x>z){
            //x>y and x>z
            cout<<x<<" is the greatest number.";
        }
        else if(x<z){
            //z>x>y
            cout<<z<<" is the greatest number.";
        }
    }
    else if(y>x){
        if(y>z){
            //y>x and y>z
            cout<<y<<" is the greatest number.";
        }
        else if(y< z){
            //z>y>x
            cout<<z<<" is the greatest number.";
        }
    }

    return 0;
}