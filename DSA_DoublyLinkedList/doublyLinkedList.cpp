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

        //4. Insering a Node after a particular node
        void insertNodeAfter(int k, Node *n)
        {
            Node* ptr = nodeExists(k);
            if(ptr == NULL)
            {
                cout<<"No node exists with key value: "<<k<<endl;
            }
            else
            {
                if(nodeExists(n->key) != NULL)
                {
                    cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value."<<endl;
                }
                else
                {
                    cout<<"INSERTING..."<<endl;

                    Node *nextNode = ptr->next;
                    //inserting at the end
                    if(nextNode==NULL)
                    {
                        ptr->next=n;
                        n->previous=ptr;
                        cout<<"Node Inserted at the END!"<<endl;
                    }
                    else //inserting in between
                    {
                        n->next=nextNode;
                        nextNode->previous=n;
                        n->previous=ptr;
                        ptr->next=n;
                        cout<<"Node Inserted!"<<endl;
                    }
                    
                }
            }
        }

        // 5. Deleting a Node by Key
        void deleteNodeByKey(int k)
        {
            Node* ptr = nodeExists(k);
            if(ptr == NULL)
            {
                cout<<"No node exists with key value: "<<k<<endl;
            }
            else
            {
                if(head->key==k)
                {
                    head = head->next;
                    cout<<"Node Unlinked with key value: "<<k<<endl;
                }
                else
                {
                    Node *nextNode = ptr->next;
                    Node *prevNode = ptr->previous;

                    //Deleting at the end
                    if(nextNode==NULL)
                    {
                        prevNode->next=NULL;
                        cout<<"Node Deleted at the END!"<<endl;
                    }

                    //Deleting in between
                    else
                    {
                        prevNode->next=nextNode;
                        nextNode->previous=prevNode;
                        cout<<"Node Deleted!"<<endl;
                    }
                }
            }
        }

        // 6. Update a Node
        void updateNodeByKey(int k, int d)
        {
            Node* ptr = nodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data=d;
                cout<<"Node Data updated successfully!"<<endl;
            }
            else
            {
                cout<<"Node Doesn't exist!"<<endl;
            }
        }

        // 7. Print list
        void printList()
        {
            if(head==NULL)
            {
                cout<<"No nodes in Doubly linked list!"<<endl;
            }
            else{
                cout<<endl<<"Doubly Linked List values: ";
                Node* temp = head;

                while(temp!=NULL)
                {
                    cout<<" ("<<temp->key<<","<<temp->data<<") <-->";
                    temp = temp->next;
                }
            }
        }
};


int main()
{
    DoublyLinkedList d;
    int option;
    int key1, k1, data1;
    do
    {
        cout<<"\nWhat operation do you want to perform? Select Option Number. Enter 0 to Exit."<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNodeAfter()"<<endl;
        cout<<"4. deleteNodeByKey()"<<endl;
        cout<<"5. updateNodeByKey()"<<endl;
        cout<<"6. print()"<<endl;
        cout<<"7. Clear Screen"<<endl;

        cin>>option;
        //n1 is a pointer to that object in heap memory
        //every time do while is executed, new memory location is allocated for n1
        Node* n1 = new Node(); //Dynamic memory allocation on Heap (GLobal, exists throughout program)
        
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Append Node operation \n Enter key and data of the Node to be appended."<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.appendNode(n1);
                break;
            case 2:
                cout<<"Prepend Node operation \n Enter key and data of the Node to be prepended."<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.prependNode(n1);
                break;
            case 3:
                cout<<"Insert Node operation \n Enter key of existing node after which you want to insert this new node: "<<endl;
                cin>>k1;
                cout<<"Enter key and data of the new node first: "<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.insertNodeAfter(k1,n1);
                break;
            case 4:
                cout<<"Delete Node By Key operation \n Enter key of Node to be deleted: "<<endl;
                cin>>k1;
                d.deleteNodeByKey(k1);
                break;
            case 5:
                cout<<"Update Node By Key operation \n Enter key & New Data to be updated: "<<endl;
                cin>>key1;
                cin>>data1;
                d.updateNodeByKey(key1, data1);
                break;
            case 6:
                d.printList();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout<<"Enter a valid option!";

        }
    } while (option!=0);
    return 0;
}