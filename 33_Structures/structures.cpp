#include <iostream>
using namespace std;

struct Person{
    char name[100];
    int age;
    double salary;
};

int main()
{
    Person p1;
    cout<<"Enter person details: "<<endl;
    cout<<"Enter person name: "<<endl;
    cin.getline(p1.name, 100);

    cout<<"Enter age: "<<endl;
    cin>>p1.age;

    cout<<"Enter salary: "<<endl;
    cin>>p1.salary;


    cout<<"Person details are as follows: "<<endl;
    cout<<"Person name: "<<p1.name<<endl;
    cout<<"Person age: "<<p1.age<<endl;
    cout<<"Person salary: "<<p1.salary<<endl;
    return 0;
}