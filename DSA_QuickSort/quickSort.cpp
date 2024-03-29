#include <iostream>
using namespace std;

int Partition(int arr[], int s, int e)
{
    int pivot = arr[e]; //Selecting last element as pivot
    int pIndex = s;

    for(int i=s; i<e; i++)
    {
        if(arr[i] <= pivot)
        {
            //swap(arr[i], arr[pIndex]);
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }

    // swap(arr[e], arr[pIndex]);
    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

void QuickSort(int arr[], int s, int e) 
{
    if(s<e)
    {
        int p = Partition(arr, s, e);
        QuickSort(arr, s, p-1);
        QuickSort(arr, p+1, e);
    }
}

int main()
{
    int size = 0;
    cout<<"Enter size of array: "<<endl;
    cin>>size;
    int myarray[size];

    cout<<"Enter "<<size<<" integers in any order: "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>myarray[i];
    }
    cout<<"Before Sorting: ";
    for(int i=0; i<size; i++)
    {
        cout<<myarray[i]<<" ";
    }
    cout<<endl;

    //Call QuickSort function
    QuickSort(myarray, 0, (size-1));

    cout<<"After Sorting: ";
    for(int i=0; i<size; i++)
    {
        cout<<myarray[i]<<" ";
    }
    cout<<endl;


    return 0;
}