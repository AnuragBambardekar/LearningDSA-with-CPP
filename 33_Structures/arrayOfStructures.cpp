#include <iostream>
#include <string>
using namespace std;

struct Person{
    string name;
    int age;
    double salary;
};

int main()
{
    Person p[3];
    cout<<"Enter details of the users: "<<endl;

    for(int i=0; i<2; i++)
    {
        cout<<"Enter details of the person: "<<i+1<<endl;
        cout<<"Enter name of the person: "<<endl;
        cin>>p[i].name;
        cout<<"Enter age of the person: "<<endl;
        cin>>p[i].age;
        cout<<"Enter salary of the person: "<<endl;
        cin>>p[i].salary;
        cout<<" "<<endl;
    }

    cout<<"Details of users: "<<endl;
    for(int i=0; i<2; i++)
    {
        cout<<"Name: "<<p[i].name<<endl;
        cout<<"Age: "<<p[i].name<<endl;
        cout<<"Salary: "<<p[i].name<<endl;
        cout<<" "<<endl;
    }
    return 0;
}