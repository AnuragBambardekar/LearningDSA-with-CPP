#include <iostream>
using namespace std;
int main()
{
    int numerator, denominator, result;
    cout<<"Enter numerator and denominator: "<<endl;
    cin>>numerator>>denominator;
    try{
        if(denominator == 0)
            {throw denominator;}
        result = numerator/denominator;
        cout<<"Division result is: "<<result;
    } catch(int e){
        cout<<"Arithmetic Error!";
    }

    return 0;
}