#include <iostream>
using namespace std;

//Create Node
class Node
{
    public:
        int key;
        int data;
        Node* next;
        Node* previous;

        //default constructor
        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
            previous = NULL;
        }

        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class DoublyLinkedList{
    public:
        Node* head; //pointer pointing to first node

        DoublyLinkedList()
        {
            head = NULL;
        }

        DoublyLinkedList(Node *n)
        {
            head = n;
        }

        // 1. Check if node exists
        Node* nodeExists(int k)
        {
            Node* temp = NULL; //temporary pointer of class Node
            Node* ptr = head;
            
            //use ptr to traverse the list
            while(ptr != NULL)
            {
                if(ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp;
        }

        // 2. Append Node to the end of list
        void appendNode(Node* n) //pass by address
        {
            //Check if node already exists
            //if nodeExists returns NULL, that means the node does not exist and can be created
            if(nodeExists(n->key) != NULL)
            {
                //node with same key value exists
                cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value."<<endl;
            }
            else
            {
                if(head == NULL)
                {
                    head = n;
                    cout<<"Node appended as Head Node!"<<endl;
                }
                else{
                    Node* ptr = head;
                    //use ptr to traverse the list to the end
                    //because appending is done at the end of the list
                    while(ptr->next != NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n; //ptr->next because ptr is last element in lisy
                    n->previous = ptr; //newly appended node needs to point back also
                    cout<<"Node Appended!"<<endl;
                }
            }
        }

        // 3. Prepend Node to the start of the Linked list
        void prependNode(Node* n)
        {
            if(nodeExists(n->key) != NULL)
            {
                cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value."<<endl;
            }
            else{
                if(head == NULL) //when node is not pointing to any nodes
                {
                    head = n;
                    cout<<"Node Appended!"<<endl;
                }
                else{
                    head->previous=n;
                    n->next = head;
                    head = n;
                    cout<<"Node prepended!"<<endl;
                }
            }
        }
};


int main()
{
    return 0;
}