#include <iostream>
using namespace std;
int main()
{
    int var = 5;

    int *ip;    //pointer to integer
    double *dp; //pointer to double
    float *fp;  //pointer to float
    char *ch;   //pointer to character

    ip = &var;
    cout<<"variable value: "<<var<<endl;
    cout<<"address in pointer: "<<ip<<endl;
    cout<<"pointer pointing to value: "<<*ip<<endl;

    *ip = 6;
    cout<<endl;
    cout<<"variable value: "<<var<<endl;
    cout<<"address in pointer: "<<ip<<endl;
    cout<<"pointer pointing to value: "<<*ip<<endl;


    return 0;
}