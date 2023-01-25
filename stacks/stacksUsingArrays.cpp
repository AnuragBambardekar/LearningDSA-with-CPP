#include <iostream>
#include <string>
using namespace std;

class Stack{
    private:
        int top;
        int arr[5];

    public:
        Stack () //constructor
        {
            top = -1;
            for(int i=0; i<5; i++)
            {
                arr[i]=0; //initialize stack with 0
            }
        }

        //check whether stack is empty
        bool isEmpty()
        {
            if(top==-1)
                return true;
            else
                return false;
        }

        //check whether stack is full
        bool isFull()
        {
            if(top==4)
                return true;
            else
                return false;
        }

        //push operation
        void push(int val)
        {
            //check whether stack is full or not
            if(isFull())
            {
                cout<<"Stack Overflow!"<<endl;
            }
            else{
                top++; //top(index) becomes 0 because stack was empty
                arr[top] = val;
            }
        }

        //push operation
        int pop()
        {
            //check whether stack is full or not
            if(isEmpty())
            {
                cout<<"Stack Underflow!"<<endl;
                return 0;
            }
            else{
                int pop_val = arr[top]; //get the top value from stack
                arr[top] = 0; //remove that element
                top--; //decrement top(index)
                return pop_val;
            }
        }

        //return count of values in stack
        int count()
        {
            return(top+1);
        }

        //return position of value in stack
        int peek(int pos)
        {
            if(isEmpty())
            {
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            else{
                return arr[pos];
            }
        }

        //change value
        void change(int pos, int val)
        {
            arr[pos] = val;
            cout<<"Value changed at location "<<pos<<endl;
        }

        //display the stack
        void display()
        {
            cout<<"All values in the stack are: "<<endl;
            for(int i=4; i>=0; i--)
            {
                cout<<arr[i]<<endl;
            }
        }

};

int main()
{
    //create an object of stack
    Stack s1;
    int option, position, value;

    //Create a menu
    do
    {
        cout<<"Select an operation to perform. Enter 0 to exit."<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. peek()"<<endl;
        cout<<"6. count()"<<endl;
        cout<<"7. change()"<<endl;
        cout<<"8. display()"<<endl;
        cout<<"9. Clear screen"<<endl<<endl;

        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter an item to push: "<<endl;
                cin>>value;
                s1.push(value);
                break;
            
            case 2:
                cout<<"Pop function Called! Popped value: "<<s1.pop()<<endl;
                break;
            
            case 3:
                if(s1.isEmpty())
                    cout<<"Stack is Empty! "<<endl;
                else
                    cout<<"Stack is Not Empty! "<<endl;
                break;

            case 4:
                if(s1.isFull())
                    cout<<"Stack is Full! "<<endl;
                else
                    cout<<"Stack is Not Full! "<<endl;
                break;

            case 5:
                cout<<"Enter position of an item to peek: ";
                cin>>position;
                cout<<"Peek function called! Value at position "<<position<<endl<<s1.peek(position)<<endl;
                break;

            case 6:
                cout<<"Count Function called! Number of items in the stack are: "<<s1.count()<<endl;
                break;

            case 7:
                cout<<"Enter position of an item to be changed: ";
                cin>>position;
                cout<<"Enter value of the item: ";
                cin>>value;
                s1.change(position,value);
                break;
            
            case 8:
                cout<<"Display function called! "<<endl;
                s1.display();
                break;
            
            case 9:
                system("cls");
                break;
            
            default:
                cout<<"Enter a correct Option number"<<endl;
        }

    }while(option!=0);
    
    return 0;
}
