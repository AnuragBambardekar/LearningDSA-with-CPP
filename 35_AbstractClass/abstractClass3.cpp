#include <iostream>
using namespace std;

//Abstract Class
class Shape{
    public:
        virtual void getArea() = 0; //pure virtual function, so no need to define as abstract class
};

class Circle: public Shape{
    public:
        //Don't initialize this function getArea(), that is not how overriding works
        //function should have same function prototype
        //implementation can be different
        void getArea() //if we don't override here, then this class will also become an abstract class
        {
            cout<<"Enter radius: ";
            int r;
            cin>>r;
            cout<<"Area of circle: "<<(3.14*r*r)<<endl;
        }
};

class Rectangle: public Shape{
    public:
        void getArea() //if we don't override here, then this class will also become an abstract class
        {
            cout<<"Enter length and breadth: ";
            int l,b;
            cin>>l;
            cin>>b;
            cout<<"Area of rectangle: "<<l*b<<endl;
        }
};

int main()
{
    //Shape s1; //Cannot instantiate abstract class
    Circle c1;
    c1.getArea();

    Rectangle r1;
    r1.getArea();
    return 0;
}