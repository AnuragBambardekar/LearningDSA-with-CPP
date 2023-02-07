#include <iostream>
using namespace std;

int main()
{
    typedef double wages;
    typedef float percent;
    wages w1 = 1000;
    wages w2 = 1500;
    percent p1 = 10.5;
    percent p2 = 15.5;

    cout<<"Wages earned by worker 1 = $"<<w1<<endl;
    cout<<"Wages earned by worker 2 = $"<<w2<<endl;
    cout<<"Worker 1 will get a raise by: "<<p1<<"%"<<endl;
    cout<<"Worker 2 will get a raise by: "<<p2<<"%"<<endl;
    return 0;
}