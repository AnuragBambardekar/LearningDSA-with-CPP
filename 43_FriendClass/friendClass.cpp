#include <iostream>
using namespace std;

class A{
    int x; //this is private by default even if it isn't specified
    friend class B;
    public:
        A(int a)
        {
            x = a;
        }
};

class B{
    public:
        void showData(A obj)
        {
            cout<<"x value is: "<<obj.x<<endl;
        }
};

int main()
{
    A obj1(5);
    B obj2;

    obj2.showData(obj1);
    return 0;
}