#include <iostream>
using namespace std;

void bubbleSort(int arr[])
{
    int iters=0;
    for(int i=0; i<5; i++)
    {
        iters++;
        for(int j=0; j<(5-i-1); j++)
        {
            if(arr[j] > arr[j+1]) //Ascending
            {
                //Swapping
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<endl<<"Number of iterations: "<<iters<<endl; 
}

void optimized_bubbleSort(int arr[])
{
    int iters=0;
    for(int i=0; i<5; i++)
    {
        iters++;
        int flag = false;
        for(int j=0; j<(5-i-1); j++)
        {
            if(arr[j] > arr[j+1]) //Ascending
            {
                //set flag = true if swap is performed
                flag = true;
                //Swapping
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
    cout<<endl<<"Number of iterations: "<<iters<<endl; 
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

    //bubbleSort(myarr); //arrays in C/C++ is by pass by address
    optimized_bubbleSort(myarr); //arrays in C/C++ is by pass by address

    /**
     * in the worst case the optimized version may still take the same number of iterations as the standard version. In the case, 
     * where the input is "4,8,9,2,1", both the standard and optimized versions of bubble sort take 5 iterations to sort the array.
    */

    cout<<endl<<"After Sorting: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<myarr[i]<<" ";
    }

    return 0;
}