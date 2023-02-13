#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
};

class HashTable{
    Node **arr; //dynamic array of nodes
    int size;
    public:
        HashTable()
        {
            arr = NULL;
            size = 0;
        }
        HashTable(int size)
        {
            arr = new Node*[size];
            for(int i=0; i<size; i++)
            {
                arr[i] = NULL;
            }
            this->size = size;
        }
        int HashFun(int data)
        {
            int key = data%size;
            return key;
        }

        void insert(int data)
        {
            int key = HashFun(data); //returns index
            //cout<<"KEY: "<<key<<endl;
            Node* temp = arr[key];
            if(temp == NULL)
            {
                arr[key] = new Node(data);
            }
            else{
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = new Node(data);
            }
            
        }

        void display()
        {
            if(arr==NULL)
            {
                cout<<"Empty HashTable."<<endl;
            }
            else
            {
                for(int i = 0; i<size; i++)
                {
                    cout<<"arr["<<i<<"] :";
                    Node* temp = arr[i];
                    while (temp!=NULL)
                    {
                        cout<<temp->data<<" ==> ";
                        temp = temp->next;
                    }
                    cout<<endl;
                    
                }
            }
        }

        //Search
        bool search(int data)
        {
            if(arr == NULL)
            {
                cout<<"HashTable is Empty."<<endl;
            }
            else
            {
                int key = HashFun(data);
                Node *temp = arr[key];
                if(temp == NULL)
                {
                    cout<<"Data not Found!"<<endl;
                    return false;
                }
                else
                {
                    while(temp != NULL)
                    {
                        if(temp->data == data)
                        {
                            cout<<data<<" found!"<<endl;
                            return true;
                        }
                        temp = temp->next;
                    }
                }
            }
            cout<<"Data Not Found!"<<endl;
            return false;
        }
};

int main()
{
    HashTable ht(6);
    ht.insert(24);
    ht.insert(25);
    ht.insert(20);
    ht.insert(30);
    ht.insert(21);
    ht.insert(27);

    ht.display();

    ht.search(30);
    ht.search(42);
    ht.search(27);
    return 0;
}