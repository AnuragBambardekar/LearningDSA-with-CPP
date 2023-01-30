

#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter 3 integers: "<<endl;
    int a,b,c;
    cin>>a>>b>>c;

    int greatest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    cout<<"Greatest number: "<<greatest<<endl;

    return 0;
}