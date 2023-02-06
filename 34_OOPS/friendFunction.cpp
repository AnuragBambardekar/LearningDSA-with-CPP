#include <iostream>
using namespace std;

class Distance
{
    private:
        int meters;
    
    public:
        Distance()
        {
            meters = 0;
        }
        void displayData()
        {
            cout<<"Meters value: "<<meters<<endl;
        }

        //function prototype
        friend void addValue(Distance &d);
};

void displayData1()
{
    //cout<<meters; //ERROR! cannot access member variable
}

//Independent function outside the class, but can access class member variables
void addValue(Distance &d)
{
    d.meters = d.meters + 5;
}

int main()
{
    Distance d1;
    d1.displayData();

    //friend function call
    addValue(d1); //pass by reference
    d1.displayData();
    return 0;
}