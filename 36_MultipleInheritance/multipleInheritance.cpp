#include <iostream>
using namespace std;

//Base Class 1
class A{
    public:
        void printMessage()
        {
            cout<<"Class A method called."<<endl;
        }
};

//Base Class 2
class B{
    public:
        void printMessage()
        {
            cout<<"Class B method called."<<endl;
        }
};

//Derived Class
class AB: public A, public B{
    //which method is being inherited here now
    //printMessage from class A or B
    public:
        void printMessage()
        {
            //cout<<"Class AB method called."<<endl;
            A::printMessage(); //ambiguity solved using Scope Resolution Operator
            B::printMessage();
            cout<<"Class AB method called."<<endl;
        }


};

int main()
{
    AB obj;
    //obj.printMessage(); //AB method called
    //obj.printMessage(); //AB::printMessage" is ambiguous
    obj.printMessage(); //A or B called
    return 0;
}