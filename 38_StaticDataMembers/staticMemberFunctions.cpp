#include <iostream>
using namespace std;

class Base{
    private:
        int x;
        static int count;
    public:

        //default constructor runs always when invoked
        Base()
        {
            //can access static members at class level
            count++;
        }

        //Static function
        static int getCount()
        {
            return count; //cannot return x since it is non static
        }
};

//initialize static member outside class
int Base::count = 0;

int main()
{
    //Do not require objects to create static members
    cout<<"Initial count: "<<Base::getCount()<<endl;

    Base obj,obj2;
    cout<<"Count after two object: "<<Base::getCount()<<endl;

    cout<<"Static Function Called: Count after two object: "<<Base::getCount()<<endl;
    return 0;
}