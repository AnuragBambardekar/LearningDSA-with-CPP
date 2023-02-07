#include <iostream>
using namespace std;

//function vs virtual function

class Base{
    public:
        void show()
        {
            cout<<"Base class show function called."<<endl;
        }
        virtual void print()
        {
           cout<<"Base class print function called."<<endl;
        }
};

class Derived: public Base{
    public:
        void show()
        {
            cout<<"Derived class show function called."<<endl;
        }
        void print()
        {
           cout<<"Derived class print function called."<<endl;
        }
};

int main()
{
    //pointer of base class
    Base *baseptr;
    Derived d1;

    baseptr = &d1;

    //runtime polymorphism
    baseptr->print(); //if removed virtual, then base class print() called
    baseptr->show(); 
    return 0;
}