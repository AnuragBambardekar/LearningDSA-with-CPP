#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int a = 10, b = 20;
    auto sum = a + b;
    cout<<"Sum= "<<sum<<endl;
    cout<< typeid(sum).name() <<endl;

    double c = 1.2, d = 2.3;
    auto sum_d = c + d;
    cout<<"Sum= "<<sum_d<<endl;
    cout<< typeid(sum_d).name() <<endl;

    auto i = 0, *p = &i;
    //auto sz = 0, pi = 3.14; //ERROR! Inconsistent types

    return 0;
}