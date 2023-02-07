#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //C-style strings
    char str1[] = "Anurag";
    cout<<"Name is: "<<str1<<endl;

    char str2[4] = "C++";
    cout<<str2<<endl;
    char str3[] = {'C','+','+','\0'};
    cout<<str3<<endl;
    char str4[4] = {'C','+','+','\0'};
    cout<<str4<<endl;

    /* char str5[100];
    cout<<"Enter your name: "<<endl;
    cin>>str5; //after whitespace nothing is printed
    cout<<str5<<endl; */

    char str6[100];
    cout<<"Enter your name: "<<endl;
    cin.getline(str6,100); //after whitespace nothing is printed
    cout<<str6<<endl;


    //C++ style Strings
    string obj = "Anurag Bambardekar";
    cout<<"Name is: "<<obj<<endl;

    cout<<"Enter a string: "<<endl;
    string obj2;
    //cin>>obj2;
    getline(cin,obj2);
    cout<<"String is: "<<obj2<<endl;
    cout<<"String length is: "<<obj2.length()<<endl;



    return 0;
}