#include <iostream>
using namespace std;

int reused = 42; //global scope
int main()
{
    int unique = 0; //block scope
    cout<<reused<<" "<<unique<<endl;

    int reused = 0;
    cout<<reused<<" "<<unique<<endl;

    cout<<::reused<<" "<<unique<<endl; //:: scope operator
    return 0;
}