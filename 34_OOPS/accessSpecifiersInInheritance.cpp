#include <iostream>
using namespace std;

//how public, protected and private modes work
class Base{
    public:
        int x;
        //Constructors to be defined in public
        Base(){
            x=5;
            y=6;
            z=7;
        }
        void printProtectedData(){
            cout<<"Y: "<<y<<endl;
        }
        void printPrivateData(){
            cout<<"Z: "<<z<<endl;
        }
    protected:
        int y;
    private:
        int z;
    
};

//public inheritance
class DerivedClass1: public Base{
    
};

//protected inheritance
class DerivedClass2: protected Base{
    
};

//private inheritance
class DerivedClass3: private Base{
    
};

void OutsideFunction(Base obj){
    cout<<"X: "<<obj.x<<endl;
    obj.printProtectedData();
    obj.printPrivateData();
    //cout<<"Y: "<<obj.y<<endl; //ERROR! since y is protected
    //cout<<"Z: "<<obj.z<<endl; //ERROR! since z is private
}

int main()
{
    Base obj1;
    OutsideFunction(obj1);

    DerivedClass1 obj2;
    //y is protected and z is private so cannot be inherited
    cout<<"Public Derived X: "<<obj2.x<<endl;

    DerivedClass2 obj3;
    //ERROR!, cannot inherit from base class when derived class is protected
    // cout<<"Protected Derived X: "<<obj3.z<<endl;

    DerivedClass3 obj4;
    //ERROR!, cannot inherit from base class when derived class is private
    // cout<<"Protected Derived X: "<<obj4.z<<endl;

    return 0;
}