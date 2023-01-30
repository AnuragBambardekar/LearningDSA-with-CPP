#include <iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int arr[5];

    public:
        Queue () //constructor
        {
            front = rear = -1;
            for(int i=0; i<5; i++)
            {
                arr[i]=0; //initialize queue with 0
            }
        }

        //check whether queue is empty
        bool isEmpty()
        {
            if(front==-1 && rear==-1)
                return true;
            else
                return false;
        }

        //check whether queue is full
        bool isFull()
        {
            if(rear==4)
                return true;
            else
                return false;
        }

        //push operation
        void enqueue(int val)
        {
            //check whether queue is full or not
            if(isFull())
            {
                cout<<"Queue Full!"<<endl;
            }
            else if(isEmpty()){
                front = 0;
                rear = 0;
                arr[rear] = val;
            }
            else {
                rear++;
                arr[rear] = val;
            }
        }

        //push operation
        int dequeue()
        {
            int x;
            //check whether queue is full or not
            if(isEmpty())
            {
                cout<<"Queue is Empty!"<<endl;
                return 0;
            }
            else if(front == rear){
                x = arr[front];
                arr[front] = 0;
                front = -1;
                rear = -1;
                return x;
            }
            else{
                x = arr[front];
                arr[front] = 0;
                front++;
                return x;
            }
        }

        //return count of values in queue
        int count()
        {
            return(rear-front+1);
        }

        //display the queue
        void display()
        {
            cout<<"All values in the queue are: "<<endl;
            for(int i=4; i>=0; i--)
            {
                cout<<arr[i]<<"   ";
            }
        }

};

int main()
{
    //create an object of queue
    Queue q1;
    int option, position, value;

    //Create a menu
    do
    {
        cout<<"Select an operation to perform. Enter 0 to exit."<<endl;
        cout<<"1. Enqueue()"<<endl;
        cout<<"2. Dequeue()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. count()"<<endl;
        cout<<"6. display()"<<endl;
        cout<<"7. Clear screen"<<endl<<endl;

        cin>>option;
        switch(option)
        {
            case 0:
                cout<<endl;
                break;
            case 1:
                cout<<"Enter an item to enqueue: "<<endl;
                cin>>value;
                q1.enqueue(value);
                cout<<endl;
                break;
            
            case 2:
                cout<<"Dequeue function Called! \nDequeued value: "<<q1.dequeue()<<endl;
                cout<<endl;
                break;
            
            case 3:
                if(q1.isEmpty())
                    cout<<"Queue is Empty! "<<endl<<endl;
                else
                    cout<<"Queue is Not Empty! "<<endl<<endl;
                break;

            case 4:
                if(q1.isFull())
                    cout<<"Queue is Full! "<<endl<<endl;
                else
                    cout<<"Queue is Not Full! "<<endl<<endl;
                break;

            case 5:
                cout<<"Count Function called! Number of items in the Queue are: "<<q1.count()<<endl;
                cout<<endl;
                break;

            case 6:
                cout<<"Display function called! "<<endl;
                q1.display();
                cout<<endl;
                break;
            
            case 7:
                system("cls");
                cout<<endl;
                break;
        
            default:
                cout<<"Enter a Correct Option number"<<endl;
                cout<<"--------------------------------"<<endl;
        }

    }while(option!=0);
    
    return 0;
}
