#include <iostream>
#include <string>
using namespace std;
int main()
{
    string largest;
    /* string s1 = "Phone";
    string s2 = "Telephone";
    string s3 = "Telephone booth"; //largest */

    
    /* string s1 = "Book";
    string s2 = "Bookrack"; //largest divergence occurs in 5th character r>k
    string s3 = "Bookkeeper"; */

    string s1 = "Grape";
    string s2 = "Grapefruit"; 
    string s3 = "Gym"; //largest divergence occurs in 2nd character y>r

    if((s1>s2) && (s1>s3))
        largest = s1;
    else if((s2>s3) && (s2>s1))
        largest = s2;
    else    
        largest = s3;
    
    cout<<"Largest: "<<largest;
    return 0;
}