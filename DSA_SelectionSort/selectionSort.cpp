#include <iostream>
using namespace std;

void selectionSort(int arr[])
{
    //array is passed by address by default
    for(int i=0; i<4; i++)
    {
        int min = i;
        for(int j=i+1; j<5; j++)
        {
            if(arr[j]<arr[min]) //ASCENDING ORDER, For DESCENDING ORDER change to >
            {
                min = j;
            }
        }

        if(min != i)
        {
            int temp=arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int myarr[5];
    cout<<"Enter 5 integers in random order: "<<endl;
    for(int i=0; i<5; i++)
    {
        cin>>myarr[i];
    }

    cout<<"UNSORTED Array: "<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<myarr[i]<<" ";
    }
    cout<<endl;

    selectionSort(myarr);
    cout<<"SORTED Array: "<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<myarr[i]<<" ";
    }
    cout<<endl;

    return 0;
}