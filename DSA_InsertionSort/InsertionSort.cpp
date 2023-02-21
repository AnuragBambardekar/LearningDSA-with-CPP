#include <iostream>
using namespace std;

void insertionSort(int arr[])
{
    int key,j=0;
    for(int i=1; i<5;i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key) //ascending order
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int myarr[5];
    cout<<"Enter 5 integers in any order: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>myarr[i];
    }

    cout<<"Before Sorting: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<myarr[i]<<" ";
    }

    insertionSort(myarr); //arrays in C/C++ is by pass by address

    cout<<endl<<"After Sorting: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<myarr[i]<<" ";
    }
}