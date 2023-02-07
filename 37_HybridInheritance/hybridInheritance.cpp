#include <iostream>
using namespace std;

class Base{
    protected:
        int val;
};

class Derived1: virtual public Base{
    public:
        Derived1(){
            val = 1;
        }
        void getValue()
        {
            //cout<<"Integer value: "<<val; //Derived val is ambiguous
            cout<<"Integer value: "<<val;
        }
};

class Derived2: virtual public Base{
    public:
        Derived2(){
            val = 2;
        }
        void getValue()
        {
            //cout<<"Integer value: "<<val; //Derived val is ambiguous
            cout<<"Integer value: "<<val;
        }
};

class Derived3: public Derived1, public Derived2{ //Rightmost class being inherited, that data has higher precedence
    //2 copies of val received
    //to get only 1 copy here, then make derived classes as virtual
    public:
        void getValue()
        {
            //cout<<"Integer value: "<<val; //Derived val is ambiguous
            cout<<"Integer value:"<<endl;
            Derived1::getValue();
        }
};

int main()
{
    Derived3 obj;
    obj.getValue();
    return 0;
}