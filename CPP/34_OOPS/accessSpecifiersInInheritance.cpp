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
            cout<<"From base Class-> Y: "<<y<<endl;
        }
        void printPrivateData(){
            cout<<"From base Class-> Z: "<<z<<endl;
        }
    protected:
        int y;
    private:
        int z;
    
};

//public inheritance
class DerivedClass1: public Base{
    public:
        void printPublicData(){
            cout<<"From Public Derived Class-> X: "<<x<<endl;
        }
        void printProtectedData(){
            cout<<"From Public Derived Class-> Y: "<<y<<endl;
        }
        //Inaccessible z
        /* void printPrivateData(){
            cout<<"From Public Public Class-> Z: "<<z<<endl;
        } */
};

//protected inheritance
class DerivedClass2: protected Base{
    public:
        void printPublicData(){
            cout<<"From Protected Derived Class-> X: "<<x<<endl;
        }
        void printProtectedData(){
            cout<<"From Protected Derived Class-> Y: "<<y<<endl;
        }
        //Inaccessible z
        /* void printPrivateData(){
            cout<<"From Private Protected Class-> Z: "<<z<<endl;
        } */
};

//private inheritance
class DerivedClass3: private Base{
    public:
        void printPublicData(){
            cout<<"From Private Derived Class-> X: "<<x<<endl;
        }
        void printProtectedData(){
            cout<<"From Private Derived Class-> Y: "<<y<<endl;
        }
        //Inaccessible z
        /* void printPrivateData(){
            cout<<"From Private Derived Class-> Z: "<<z<<endl;
        } */
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
    obj2.printPublicData();
    obj2.printPrivateData(); //From Base Class
    obj2.printProtectedData();


    DerivedClass2 obj3;
    //ERROR!, cannot inherit from base class when derived class is protected
    // cout<<"Protected Derived X: "<<obj3.z<<endl;
    obj3.printPublicData();
    obj3.printProtectedData();

    DerivedClass3 obj4;
    //ERROR!, cannot inherit from base class when derived class is private
    // cout<<"Protected Derived X: "<<obj4.z<<endl;
    obj4.printPublicData();
    obj4.printProtectedData();

    return 0;
}