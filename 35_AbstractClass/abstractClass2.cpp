#include <iostream>
using namespace std;

//function vs virtual function

class Animal{
    public:
        virtual void eat()
        {
            cout<<"I am eating generic food."<<endl;
        }
};

class Cat: public Animal{
    public:
        void eat()
        {
            cout<<"I am eating a rat."<<endl;
        }
};

class Dog: public Animal{
    public:
        void eat()
        {
            cout<<"I am eating dog food."<<endl;
        }
};

void function(Animal *xyz){
    xyz->eat();
}

int main()
{
    Animal *ptr;

    Cat c1;
    Dog d1;

    //Dynamic (runtime) polymorphism
    ptr = &c1;
    function(ptr); //base class eat() called when not virtual

    ptr = &d1;
    function(ptr); //base class eat() called when not virtual
    return 0;
}