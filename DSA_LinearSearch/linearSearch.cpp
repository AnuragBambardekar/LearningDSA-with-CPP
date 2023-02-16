#include <iostream>
using namespace std;

void linearSearch(int a[], int n)
{
    int temp = -1;
    for(int i=0; i<5; i++)
    {
        if(a[i]==n)
        {
            cout<<"Element found at index: "<<i<<endl;
            temp=0;
        }
    }

    if(temp==-1)
    {
        cout<<"No Element Found!";
    }

}

int main()
{
    //int arr[5] = {1,33,45,6,8};
    int arr[5];
    cout<<"Please enter elements: "<<endl;
    for(int i=0; i<5; i++)
    {
        cin>>arr[i];
    }

    cout<<"Please enter an element to search: "<<endl;
    int num;
    cin>>num;

    //linearSearch(arr, num);
    linearSearch(arr, num);
    return 0;
}