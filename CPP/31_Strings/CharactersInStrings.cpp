#include <iostream>
#include <string>
using namespace std;
int main()
{
    string readMe ("Hello There");
    for (auto ch: readMe)
        cout<<ch<<endl;   

    string readMe2 = "Hello, There!!!";
    int punct_count = 0;
    for(auto ch: readMe2)
        if(ispunct(ch))
            ++punct_count;
    cout<<"Number of punctuation characters in: "<<readMe2<<"= "<<punct_count<<endl;

    //convert all chars to uppercase
    string readMe3 = "Hello, There!!!";
    for(auto &ch: readMe3)
        ch = toupper(ch);
    cout<<"Converted string: "<<readMe3<<endl;

    return 0;
}