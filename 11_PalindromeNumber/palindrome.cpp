#include <iostream>
using namespace std;
int main()
{
    int num, n, digit, rev=0;
    cout<<"Enter a number: ";
    cin>>num;

    n = num;

    while(num!=0)
    {
        digit = num%10;
        rev = (rev*10) + digit;
        num = num/10;        
    }

    if(rev == n){
        cout<<n<<" is a Palindrome Number";
    }
    else{
        cout<<n<<" is Not a Palindrome Number";
    }

    return 0;
}