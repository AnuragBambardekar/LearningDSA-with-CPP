#include <iostream>
using namespace std;

extern const int buffsize1; //get buffsize from other file
int main()
{
    const int buffsize = 256;
    //buffsize = 512; //ERROR, const cannot be redefined
    // const int k; //const has to be initialized while declaring it

    int a = 21;
    const int ci = a;
    int b = ci;

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<ci<<endl;
    cout<<buffsize<<endl;
    cout<<buffsize1<<endl;

}