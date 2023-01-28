#include <iostream>
using namespace std;

int main()
{
    cout<<"Arithmetic Operations"<<endl; //endl so that cursor moves on to next line
    
    int option_no,x,y;
    
    do
    {
        cout<<"1. Addition"<<endl<<"2. Subtraction"<<endl<<"3. Multiplication"<<endl<<"4. Division"<<endl<<"5. Modulo"<<endl<<"6. Exit"<<endl;
        cout<<"Enter a menu option to perform the corresponding operation: "<<endl;
        cin>>option_no;

    

    switch(option_no)
    {
        case 1:
            cout<<"Addition Operation "<<endl<<"Enter 2 numbers: "<<endl;
            cin>>x>>y;
            cout<<"Addition of "<<x<<" and "<<y<<" is "<<(x+y)<<endl;
            break;
        case 2:
            cout<<"Subtraction Operation "<<endl<<"Enter 2 numbers: "<<endl;
            cin>>x>>y;
            cout<<"Subtraction of "<<x<<" and "<<y<<" is "<<(x-y)<<endl;
            break;
        case 3:
            cout<<"Multiplication Operation "<<endl<<"Enter 2 numbers: "<<endl;
            cin>>x>>y;
            cout<<"Multiplication of "<<x<<" and "<<y<<" is "<<(x*y)<<endl;
            break;
        case 4:
            cout<<"Division Operation "<<endl<<"Enter 2 numbers: "<<endl;
            cin>>x>>y;
            cout<<"Division of "<<x<<" and "<<y<<" is "<<(x/y)<<endl;
            break;
        case 5:
            cout<<"Modulo Operation "<<endl<<"Enter 2 numbers: "<<endl;
            cin>>x>>y;
            cout<<"Modulo of "<<x<<" and "<<y<<" is "<<(x%y)<<endl;
            break;
        case 6:
            cout<<"Exited the Application!"<<endl;
            break;
        default:
            cout<<"Invalid Option!"<<endl;
    }
    }while(option_no != 6);
    return 0;
}