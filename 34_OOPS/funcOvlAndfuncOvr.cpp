#include <iostream>
using namespace std;

class Animal{
    public:
        void makeSound()
        {
            cout<<"Animals Sound!";
        }
};

class Dog: public Animal{
    public:
        //if we comment the following function then Base class function
        // with same name is invoked!
        void makeSound()
        {
            cout<<"Dogs Bark!";
        }
};

class Cat: public Animal{
    public:
        void makeSound()
        {
            cout<<"Cats Meow!";
        }
};

int main()
{
    Animal a1;
    a1.makeSound();
    cout<<endl;
    
    Dog d1;
    d1.makeSound();
    cout<<endl;

    Cat c1;
    c1.makeSound();
    cout<<endl;
    return 0;
}