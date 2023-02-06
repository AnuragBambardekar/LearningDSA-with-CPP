#include <iostream>
using namespace std;

//Complex Numbers
class ComplexNumber{
    private:
        //member variables
        int real;
        float imaginary;

    public:
        ComplexNumber()
        {

        }
        ComplexNumber(int r, float i)
        {
            real = r;
            imaginary = i;
        }
        void displayData()
        {
            cout<<"Complex number: "<<real<<" + "<<imaginary<<"i"<<endl;
        }

        //Because real and imaginary are private variables
        int getRealPart()
        {
            return real;
        }
        float getImaginaryPart()
        {
            return imaginary;
        }

};

//Function
ComplexNumber add2numbers(ComplexNumber n1, ComplexNumber n2)
{
    int r;
    float i;
    r = n1.getRealPart() + n2.getRealPart();
    i = n1.getImaginaryPart() + n2.getImaginaryPart();
    ComplexNumber temp(r,i); //New object
    return temp;
}

int main()
{
    ComplexNumber comp1(5,4), comp2(5,4), comp3;
    comp3 = add2numbers(comp1, comp2);
    comp1.displayData();
    comp2.displayData();

    cout<<"Addition of comp1 and comp2: "<<endl;
    comp3.displayData();

    ComplexNumber *ptr1;
    ptr1 = &comp3;
    cout<<"Pointer to object: "<<endl;
    ptr1->displayData();
    cout<<ptr1<<endl;

    ptr1 = &comp2;
    ptr1->displayData();
    cout<<ptr1<<endl;
    return 0;
}