#include <iostream>
using namespace std; //standard I/O library

int main()
{
    //[datatype] variable_name;
    int x; //variable declaration
    x=5; //initializing a variable
    int file_size, counter=0; //garbage value if uninitialized

    int y = x+5;

    cout<<"Value of variable x is: "<<x<<"\n";
    cout<<"Value of variable x is: "<<y<<"\n";

    cout<<"File size: "<<file_size<<"\n";
    cout<<"Counter: "<<counter<<"\n";

    //Swapping
    int a =1;
    int b=2;
    int temp = a;
    a = b;
    b = temp;
    std::cout <<a<<"\n";

    //constants
    double pi = 3.14;
    pi = 0;

    const double PI = 3.14;
    std::cout <<pi<<"\n";
    std::cout <<PI<<"\n";

    //Naming conventions [hover over variable to know the case type]
    int file_Size; //snake case
    int FileSize; //Pascal case
    int fileSize; //camel case
    int iFileSize; //hungarian notation

    //Operations
    int x1 = 10;
    int y1 = 3;
    double y_1 = 3;
    int z1 = x1+y1;
    int z2 = x1-y1;
    int z3 = x1*y1;
    int z4 = x1/y1;   //quotient
    int z_4 = x1/y_1; //quotient
    int z5 = x1%y1;   //remainder
    std::cout <<z1<<"\n";
    std::cout <<z2<<"\n";
    std::cout <<z3<<"\n";
    std::cout <<z4<<"\n";
    std::cout <<z_4<<"\n";
    std::cout <<z5<<"\n";

    int z6 = x1++;
    std::cout <<z6<<"\n";
    std::cout <<x1<<"\n";

    std::cout <<x1++<<"\n";
    std::cout <<++x1<<"\n";

    return 0;
}