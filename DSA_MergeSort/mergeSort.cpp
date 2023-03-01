#include <iostream>
using namespace std;

//Merge function
void merge(int arr[], int l, int m, int r)
{
    //keep track of all indices (left subarray, right subarray, temp array)
    int i=l; //starting index of left subarray
    int j=m+1; //starting index of right subarray
    int k=l; //starting index of temp array to store sorted elements

    int temp[5]; //temp array

    while(i<=m && j<=r)
    {
        //iterate from i=0 to i=2 and j=3 to j=4
        //Comparison of elements
        if(arr[i]<=arr[j])
        {
            temp[k] = arr[i]; //arr[i] is smaller than arr[j]
            i++;
            k++;
        }
        else {
            temp[k] = arr[j]; //arr[j] is smaller than arr[i]
            j++;
            k++;
        }
    }

    while(i<=m)
    { 
        temp[k] = arr[i]; //copying all elements from left subarray to temp as it is
        i++;
        k++;
    }
    while(j<=r)
    {
        temp[k] = arr[j]; //copying all elements from right subarray to temp as it is
        j++;
        k++;
    }

    // copy elements from temp array to original array
    for(int s=l; s<=r; s++)
    {
        arr[s] = temp[s];
    }
}

//Merge Sort Function/Algorithm
void mergeSort(int arr[], int l, int r)
{
    // check whether smaller subarray has exhausted
    if(l<r)
    {
        //Calculate middle element
        int m = (l+r)/2;

        //Call Mergesort on left subarray
        mergeSort(arr,l,m);

        //Call Mergesort on right subarray
        mergeSort(arr,m+1,r);

        //Call Merge function
        merge(arr,l,m,r);
    }
}



int main()
{
    // int arr[5] = {4,6,1,2,7};
    int myarr[5];
    cout<<"Enter 5 elements in the array: "<<endl;
    for(int i=0; i<5; i++)
    {
        cin>>myarr[i];
    }

    cout<<"Before Merge Sort: "<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<myarr[i]<<" ";
    }

    // Call MergeSort Function
    //left index=0
    //right index=4
    mergeSort(myarr,0,4);
    
    cout<<endl<<"After Merge Sort: "<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<myarr[i]<<" ";
    }
    return 0;
}