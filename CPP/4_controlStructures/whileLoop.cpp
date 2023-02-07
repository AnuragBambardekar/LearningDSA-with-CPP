#include <iostream>
using namespace std;

int main()
{
    char i;
    cout<<"Enter a character. Press x to quit."<<endl;
    cin>>i;
    while(i!='x')
    {
        cout<<"Hello World!\n"<<"Enter a character. Press x to quit.";
        cin>>i;
    }
    return 0;
}