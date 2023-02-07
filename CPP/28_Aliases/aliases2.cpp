#include <iostream>
using namespace std;

int main()
{
    using letter = char;
    using num = int;
    letter a = 'A';
    letter b = 'B';
    num n1 = 65;
    num n2 = 66;

    cout<<"ASCII value of: "<<a<<" is "<<n1<<endl;
    cout<<"ASCII value of: "<<b<<" is "<<n2<<endl;
    return 0;
}