#include <iostream>
using namespace std;

//Pointers to const
int main()
{
    const double PI = 3.14;
    //double *cptr = &PI; //ERROR
    const double *cptr = &PI; //holds memory address
    cout<<cptr<<endl;
    //*cptr = 42; //ERROR
    double dval = 3.14;
    cptr = &dval; //now cptr points to dval //holds memory address
    cout<<cptr<<endl;

    //const pointers
    //read these declarations from right to left for understanding
    int errNumb = 2023;
    int *const curErr = &errNumb; //curErr is a const pointer to an object of type int
    cout<<curErr<<endl;

    const double pii = 3.14;
    const double *const pip = &pii; //pii is a const pointer to an object of type const double
    cout<<pip<<endl;



}