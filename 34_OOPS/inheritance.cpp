#include <iostream>
using namespace std;

class Shape
{
    protected:
        int width;
        int height;
    public:
        void setWidth(int w)
        {
            width = w;
        }
        void setHeight(int h)
        {
            height = h;
        }
};

//Derived Class
class Rectangle: public Shape{
    public:
        int getArea()
        {
            return (width * height);
        }
};

int main()
{
    Rectangle rect;

    rect.setWidth(5);
    rect.setHeight(6);
    cout<<"Total Area: "<<rect.getArea()<<endl;
    return 0;
}