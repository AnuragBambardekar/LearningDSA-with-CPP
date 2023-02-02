#include <iostream>
#include <string>
using namespace std;
int main()
{
    /* cout<<"Enter string: "<<endl;
    string readMe;
    cin>>readMe; //text after whitespace is ignored!
    cout<<readMe<<endl; */

    /* cout<<"Enter again: "<<endl;
    string readMe1, readMe2;
    cin>>readMe1>>readMe2; //text after whitespace is ignored!
    cout<<readMe1<<" "<<readMe2<<endl; */

    /* cout<<"Enter again: "<<endl;
    string readMe3;
    while(cin>>readMe3) //Ctrl + Z to Exit
    cout<<readMe3<<endl; // new line */

    //Using getline
    cout<<"Enter again: "<<endl;
    string readMe4;
    while(getline(cin, readMe4)) //Ctrl + Z to Exit
    cout<<readMe4<<endl; //single line
    return 0;
}