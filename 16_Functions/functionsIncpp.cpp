#include <iostream>
using namespace std;

int maximum(int x, int y){
    if(x>y){
        return x;
    } else {
        return y;
    }
}

int maximum_defined_after_main(int x, int y); //forward declaration

void printMessage(){
    cout<<"Hello World!";
}

int main()
{
    int a,b;
    cout<<"Enter two numbers: "<<endl;
    cin>>a>>b;

    int c = maximum(a,b);
    cout<<c<<" is the greatest value"<<endl;

    int d = maximum_defined_after_main(a,b);
    cout<<d<<" is the greatest value"<<endl;

    cout<<"The greatest value: "<< maximum(a,b)<<endl;

    printMessage();

    return 0;
}

int maximum_defined_after_main(int x, int y){
    if(x>y){
        return x;
    } else {
        return y;
    }
}