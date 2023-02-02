#include <iostream>
using namespace std;

//Constant Expressions

int get_size(){}
int main()
{
    const int max_files = 20; //max_files is a constant expression
    const int limit = max_files + 1; //limit is a constant expression

    int staff_size = 27; //not a const expression
    const int sz = get_size(); //sz is not a const expression, because get_size() is determined at runtime


    //constexpr
    constexpr int mf = 20;
    constexpr int limit = mf + 1;

    //pointers and constexpr
    const int *p = nullptr; //p is a pointer to a const int
    constexpr int *q = nullptr; //q is a const pointer to int

    const int j =0;
    constexpr int i = 42;

}