#include <iostream>
#include <chrono>
using namespace std;

//inline function
inline int add(int a, int b)
{
    return a+b;
}

int add_1(int a, int b)
{
    return a+b;
}

int main()
{
    //no control transfer from main() to inline int add()
    auto start = std::chrono::high_resolution_clock::now();

    cout<<"Addition of 4 and 5 is: "<<add(4,5)<<endl;
    //cout<<"Addition of 4 and 5 is: "<<add_1(4,5)<<endl;

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout << "Elapsed time: " << elapsed.count() << " s\n";
    //Elapsed time: 0.000354 s for inline execution
    //Elapsed time: 0.001091 s for regular function
    return 0;
}
