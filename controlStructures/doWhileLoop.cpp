#include <iostream>
using namespace std;

int main()
{
    char i;
    do
    {
        cout<<"Hello World!\n"<<"Enter a character. Press x to quit.";
        cin>>i;
    }while(i!='x');
    return 0;
}