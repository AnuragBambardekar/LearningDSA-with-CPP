#include <iostream>
#include <string>
using namespace std;
int main()
{
    string readMe;

    while(getline(cin,readMe))
    
    //empty
    if(!readMe.empty())
    {
        cout<<"String is: "<<endl;
        cout<<readMe<<endl;

        //size
        auto len = readMe.size();
        cout<<"Length of string: "<<len<<endl;
    }
    else{
        cout<<"String is empty";
    }

    return 0;
}