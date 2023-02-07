#include <iostream>
using namespace std;
int main()
{
    int my_arr1[3][3];
    int my_arr2[2][2] = {1,2,3,4};
    int my_arr3[3][3] = {{1,1,1},{2,2,2},{3,3,3}};
    
    cout<<"Array 3: "<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<my_arr3[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter values for 3x3 matrix: "<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cin>>my_arr1[i][j];
        }
    }

    cout<<"Entered 3x3 matrix: "<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<my_arr1[i][j]<<" ";
        }
        cout<<endl;
    }

    //Addition and Subtraction
    int add[2][2], sub[2][2];

    cout<<"Addition of 3x3 matrices: "<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<my_arr1[i][j] + my_arr3[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Subtraction of 3x3 matrices: "<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<my_arr1[i][j] - my_arr3[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}