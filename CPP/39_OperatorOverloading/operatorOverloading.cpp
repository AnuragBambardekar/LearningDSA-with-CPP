#include <iostream>
using namespace std;

class Complex{
    private:
        int real, img;
    public:
        Complex(){
            real = 0;
            img = 0;
        }
        Complex(int r, int i){
            real = r;
            img = i;
        }
        void print(){
            cout<<real<<" + "<<"i"<<img<<endl;
        }

        //Operator Overloading Syntax
        Complex operator +(Complex c)
        {
            Complex temp;
            temp.real = real + c.real;
            temp.img = img + c.img;
            return temp;
        }
};

int main()
{
    //user defined objects
    Complex c1(5,4);
    Complex c2(2,5);
    Complex c3;
    Complex c4;

    c3 = c1 + c2; //c3 = c1.add(c2)-->logic
    c3.print();
    c4 = c1 + c2 + c3;
    c4.print();

    //Primitive datatypes
    int x = 5;
    int y = 4;
    int z = x+y;
    cout<<"z value: "<<z<<endl;
}
