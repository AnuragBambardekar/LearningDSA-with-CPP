#include <iostream>
using namespace std;

//Function Overloading
/* int add(int x, int y)
{
    return (x+y);
}
float add(float x, float y)
{
    return (x+y);
}
double add(double x, double y)
{
    return (x+y);
} */

//Function Template
template <typename T>
T add(T x, T y)
{
    return (x+y);
}
///What if I want different params
template <typename T, typename U>
U add(T x, U y) //when T, returns int
{
    return(x+y);
}

int main(){
    //cout<<"Addition of 2 integers: "<<add(3,4)<<endl;
    cout<<"Addition of 2 integers: "<<add<int>(3,4)<<endl;
    cout<<"Addition of 2 doubles: "<<add<double>(3.23,4.42)<<endl;
    cout<<"Addition of 2 floats: "<<add<float>(3.4f,4.5f)<<endl;
    cout<<"Addition of 2 variables of different datatypes: "<<add<int, double>(3,4.5)<<endl;
}