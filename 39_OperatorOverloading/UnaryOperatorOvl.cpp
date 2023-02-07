#include <iostream>
using namespace std;

class Weight{
    private:
        int kg;
    public:
        Weight()
        {
            kg = 0;
        }
        Weight(int x)
        {
            kg = x;
        }
        void printWeight()
        {
            cout<<"Weight in KG: "<<kg<<endl;
        }

        /* void operator ++()
        {
            ++kg;
        } */
        void operator ++(int) //post
        {
            kg++;
        }

        void operator --()
        {
            --kg;
        }
        void operator --(int) //post
        {
            kg--;
        }

        Weight operator ++()
        {
            Weight temp;
            temp.kg = ++kg;
            return temp;
        }
};

int main()
{
    //Unary operator overloading
    Weight obj;
    obj.printWeight();
    ++obj; 
    obj.printWeight();
    obj++; //obj.operator++(); behind the scenes    
    obj.printWeight();

    --obj; 
    obj.printWeight();
    obj--; //obj.operator--(); behind the scenes    
    obj.printWeight();

    Weight obj1, obj2;
    obj2 = ++obj1; //needs to return object of weight type and assign it to obj2, but operator overloading function interferes
    obj2.printWeight();

    ++obj2;
    obj2.printWeight();

    //Primitive datatypes
    int x = 0;
    int y = 0;
    ++x;
    x++;
    y=++x;
    cout<<x<<endl;
    return 0;
}