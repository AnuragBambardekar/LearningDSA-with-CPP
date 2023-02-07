#include <iostream>
using namespace std;

//Top level and Low level const
int main()
{
    int i = 0;
    int *const p1 = &i; //const is top level
    const int ci = 42;  //const is top level
    const int *p2 = &ci; //const is low level, object to which p2 points is const
    const int *const p3 = p2; //p3 pointing to const int p2, p2 pointing to ci, leftmost const is low level, and rightmost const is top level

    const int &r = ci; //const in reference types is always low level

    //Rules
    //Distinction between top level and low level matters when we copy an object
    //When we copy an object, top level const's are ignored
    //Low level cont is never ignored
    //When we copy an object, both objects must have the same low level const qualification or there must be a conversion between the types of 2 objects
    //In general, we can convert a non-const to const but not the other way round.

    //Example
    i = ci; //OK, copying value of ci, top level const in ci is ignored
    p2 = p3; //OK, pointed-ro type matches, top level const in p3 is ignored
    //int *p = p3; //ERROR!, p3 has a low level const but p doesn't
    p2 = &i; //OK, we can convert int* to const int*
    //int &r = ci; // ERROR!, cannot bind an ordinary int to a const int object
    const int &r2 = i; //OK, can bind const int & to plain int


}