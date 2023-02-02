#include <iostream>
using namespace std;

int main()
{
    typedef char *pstring; //pstring is an alias for type char
    const pstring cstr = 0; //cstr is a const pointer to char
    const pstring *ps; //ps is a pointer to a const pointer to char
    //const char *cstr = 0; //ERROR!, cstr a pointer to const char

    return 0;
}