#include <iostream>
using namespace std;

int add(int a, int b)
{
    return (a+b);
}

double add(double a, double b)
{
    return (a+b);
}

float add(float a, float b)
{
    return (a+b);
}

//overload with more variables
int add(int a, int b, int c)
{
    return a+b+c;
}

double add(int a, double b)
{
    return a+b;
}

double add(double a, int b)
{
    return a+b;
}

int main()
{
    cout<<"Function 1: int add(int a, int b):          "<<add(1,2)<<endl;
    cout<<"Function 2: double add(double a, double b): "<<add(1.6,2.9)<<endl;
    cout<<"Function 3: float add(float a, float b):    "<<add(1.4,2.2)<<endl;
    cout<<"Function 4: int add(int a, int b, int c):   "<<add(1,2,3)<<endl;
    cout<<"Function 5: double add(int a, double b):    "<<add(1,2.5)<<endl;
    cout<<"Function 6: double add(double a, int b):    "<<add(1.75,2)<<endl;
    return 0;
}