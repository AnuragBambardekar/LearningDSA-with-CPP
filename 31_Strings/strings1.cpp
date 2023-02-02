#include <iostream>
#include <string>
using namespace std;

int main()
{
    string imempty;
    string helloThere ("Hello World!");
    string theReply = "Hello There!";
    imempty = "I am doing well. How are you?";
    string theAnswer = imempty;

    string aLot (10,'s');
    string someSs (aLot);
    string theRequest ("Can I get a cup of coffee? Thanks");

    cout<<helloThere<<endl<<theReply<<endl<<theAnswer<<endl<<theRequest
    <<someSs<<endl;
}