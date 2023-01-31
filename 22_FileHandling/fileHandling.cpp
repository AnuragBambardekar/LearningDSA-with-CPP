//pre-processor directives
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char arr[100];
    cout<<"Enter your name and age: "<<endl;
    cin.getline(arr,100);
    //cin>>arr // ignores space and characters after it, therefore used getline

    //Writing to file
    //ofstream myfile("xyz.txt"); //creates/opens file; file is overwritten with new content
    ofstream myfile("xyz.txt",ios::app); //creates/opens file
    
    myfile<<arr;
    myfile.close();
    cout<<"File Write Operation performed successfully!"<<endl;

    //Reading from file
    char arr1[100];
    cout<<"Reading from File"<<endl;
    ifstream obj("xyz.txt");
    obj.getline(arr1,100);
    cout<<"Array content: "<<arr1;
    return 0;
}