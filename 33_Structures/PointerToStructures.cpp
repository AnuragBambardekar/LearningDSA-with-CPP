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
    Person p; //Person p1,p2,p3,p4;
    //Pointers are useful when we have multiple objects of the structure and want
    //to point to each instance according to some criteria
    cout<<"Enter details of the users: "<<endl;

    
    /* cout<<"Enter details of the person: "<<i+1<<endl;
    cout<<"Enter name of the person: "<<endl;
    cin>>p.name;
    cout<<"Enter age of the person: "<<endl;
    cin>>p.age;
    cout<<"Enter salary of the person: "<<endl;
    cin>>p.salary;
    cout<<" "<<endl; */
    

    /* cout<<"Details of users: "<<endl;
    cout<<"Name: "<<p[i].name<<endl;
    cout<<"Age: "<<p[i].name<<endl;
    cout<<"Salary: "<<p[i].name<<endl;
    cout<<" "<<endl; */
    

    //Create a pointer
    Person *ptr = &p;
    cout<<"Enter name of the person: "<<endl;
    cin>>ptr->name;
    cout<<"Enter age of the person: "<<endl;
    cin>>ptr->age;
    cout<<"Enter salary of the person: "<<endl;
    cin>>ptr->salary;
    cout<<" "<<endl;

    cout<<"Details of users: "<<endl;
    cout<<"Name: "<<ptr->name<<endl;
    cout<<"Age: "<<ptr->age<<endl;
    cout<<"Salary: "<<ptr->salary<<endl;
    cout<<" "<<endl;
    return 0;
}