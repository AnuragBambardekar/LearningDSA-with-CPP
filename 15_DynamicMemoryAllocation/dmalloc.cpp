#include <iostream>
using namespace std;
int main()
{
    int size;
    int *ptr;

    cout<<"Enter number of values to be stored (size of array): "<<endl;
    cin>>size;

    //create an array dynamically
    ptr = new int[size];

    cout<<"Enter values: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>ptr[i];
    }
    cout<<"Entered values: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<ptr[i]<<endl;
    }

    return 0;
}