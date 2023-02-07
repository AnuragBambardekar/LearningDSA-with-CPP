#include <iostream>
using namespace std;

class Base{
    public:
        int x;
        static int count;

        //default constructor runs always when invoked
        Base()
        {
            //can access static members at class level
            count++;
        }
};

//initialize static member outside class
int Base::count = 0;

int main()
{
    //Do not require objects to create static members
    cout<<"Initial count: "<<Base::count<<endl;

    Base obj,obj2;
    cout<<"Count after two object: "<<Base::count<<endl;
    return 0;
}