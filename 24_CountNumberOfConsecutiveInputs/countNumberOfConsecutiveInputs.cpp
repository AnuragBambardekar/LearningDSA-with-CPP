#include <iostream>
using namespace std;
int main()
{
    int currVal = 0, val = 0;
    if(cin>>currVal)
    {
        int cnt = 1;
        while(cin>>val) //read remaining numbers, exit when EOF character entered
        {
            if(val == currVal)
            {
                ++cnt;
            }
            else
            {
                cout<<currVal<<" occurs "<<cnt<<" times."<<endl;
                currVal = val; //store new value
                cnt = 1; //reset counter
            }
        }
        cout<<currVal<<" occurs "<<cnt<<" times."<<endl; //print last value count
    }
    return 0;
}