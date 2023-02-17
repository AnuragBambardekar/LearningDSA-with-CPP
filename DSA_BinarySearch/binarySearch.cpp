#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(arr[mid] == x)
        {
            return mid;
        }
        else if(arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return {-1};
}

int main()
{
    int num;
    int myarr[10];
    int output;

    cout<<"Enter 10 integers in ASCENDING order: "<<endl;
    for(int i=0; i<10; i++)
    {
        cin>>myarr[i];
    }

    cout<<"Enter element to be searched in the array: "<<endl;
    cin>>num;

    output = binarySearch(myarr,0,9,num);
    if(output == -1)
    {
        cout<<"Number "<<num<<" not found in the array!"<<endl;
    }
    else
    {
        cout<<"Match found at index: "<<output<<endl;
    }

    return 0;
}