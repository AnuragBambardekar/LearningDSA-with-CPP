#include <iostream>
using namespace std;

//algorithm 1
void sumOfNumbers1(double n)
{
    double sum=0;
    for(int i=1; i<=n; i++)
    {
        sum = sum + i;
    }
    cout<<"Method 1: Sum of "<<n<<" numbers is: "<<sum<<endl;
    // Takes more than 30 seconds
}


//algorithm 2
void sumOfNumbers2(double n)
{
    double sum = (n * (n+1)/2);
    
    cout<<"Method 2: Sum of "<<n<<" numbers is: "<<sum<<endl;
    // immediately returns Answer
}

int main()
{
    double num;
    cout<<"Enter number limit till which you want to calculate sum: "<<endl;
    cin>>num;

    //sumOfNumbers1(num);
    sumOfNumbers2(num);
    return 0;
}