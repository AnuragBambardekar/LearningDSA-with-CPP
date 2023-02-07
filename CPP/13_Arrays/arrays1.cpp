#include <iostream>
using namespace std;
int main()
{
    int arr[3] = {1,2,3};
    double arr1[5];
    arr1[0] = 1.123;
    arr1[2] = 3.492;

    char myarr[4];
    myarr[0]='a';

    int temp_arr[5];
    cout<<"Enter 5 integers: "<<endl;
    for(int i = 0; i<5; i++)
    {
        cin>>temp_arr[i];
    }
    cout<<"Array values: "<<endl;
    for(int i = 0; i<5; i++)
    {
        cout<<temp_arr[i]<<endl;
    }
}