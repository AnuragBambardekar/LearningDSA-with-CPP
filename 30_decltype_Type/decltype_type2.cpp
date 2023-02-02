#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
    int i = 42, *p = &i, &r = i;
    decltype(r+0)b;
    //decltype(*p)c; //ERROR!, uninitialized
    decltype(*p) c = i; //must be an l-value (identifiable location)
    //decltype((i)) d; //ERROR!
    decltype((i)) d = b;
    decltype(i) e;

    cout<<typeid(i).name()<<endl;
    cout<<typeid(p).name()<<endl;
    cout<<typeid(r).name()<<endl;
    cout<<typeid(b).name()<<endl;
    cout<<typeid(c).name()<<endl;

    cout<<"i: "<<i<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"r: "<<r<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;
    cout<<"d: "<<d<<endl;
    cout<<"e: "<<e<<endl;
    return 0;
}