#include <iostream>
using namespace std;

class Node
{
    public:
        int key;
        int data;
        Node* next;

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
        }
        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class CircularLinkedList
{
    public:
        Node* head;

        CircularLinkedList()
        {
            head = NULL;
        }

        // 1. Check if the node exists
        //refer image in folder: ChecknodeExists.png
        Node* nodeExists(int k) //method which returns a pointer, pass the key value of the node
        {
            //traverse through singly linked list to check if key=k exists
            Node* temp = NULL;
            Node* ptr = head; //use ptr to traverse list

            if(ptr == NULL)
            {
                return temp;
            }
            else
            {
                //we use do..while because it's exit controlled
                do
                {
                    if(ptr->key == k)
                    {
                        temp=ptr; //key exists in the linked list, so store it in temp
                    }
                    ptr = ptr->next; //point to next node
                } while (ptr!=head); //last node is pointing to head
                //executes until we arrive back to head
                return temp;
            }
        }

        // 2. Append Node to the end of linked list
        //refer image in folder: appendNode.png
        void appendNode(Node *n) //Pass the node to be appended
        {
            //Check if node already exists
            //if nodeExists returns NULL, that means the node does not exist and can be created
            if(nodeExists(n->key) != NULL)
            {
                //node with same key value exists
                cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value."<<endl;
            }
            else{
                //when no node attached in singly linked list
                if(head == NULL) //when node is not pointing to any nodes
                {
                    head = n;
                    n->next = head;
                    cout<<"Node Appended!"<<endl;
                }
                else //head pointer is pointing to some other node, there are other nodes in singly linked list
                {
                    
                    Node* ptr = head;
                    while(ptr->next!=head) //since circular
                    {
                        ptr = ptr->next;
                    }
                    ptr->next=n;
                    n->next=head; //since this is circular
                    cout<<"Node Appended!"<<endl;
                    
                }
            }
        }

        // 3. Prepend Node to the start of the Linked list
        //refer image in folder: prependNode.png
        void prependNode(Node* n)
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
                if(head==NULL)
                    {
                        head = n;
                        n->next = head;
                        cout<<"Node prepended at first position"<<endl;
                    }
                    else
                    {
                        Node* ptr = head;
                        //Traverse to end of list to change tail's next pointer
                        while(ptr->next!=head)
                        {
                            ptr = ptr->next;
                        }
                        ptr->next=n;
                        n->next=head;
                        head=n;
                        cout<<"Node prepended!"<<endl;
                    }
            }
        }

        // 4. Insert a Node after a particular node in the linked list
        void insertNodeAfter(int k, Node *n) //key of node after which we want to attache new node n
        {
            Node* ptr = nodeExists(k); //point to node whose key value is k, ptr will store the address
            if(ptr == NULL)
            {
                cout<<"No node exists with key value: "<<k<<endl;
            }
            else
            {
                if(nodeExists(n->key) != NULL)
                {
                    //node with same key value exists
                    cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value."<<endl;
                }
                else
                {
                    if(ptr->next==head)
                    {
                        n->next=head;
                        ptr->next=n;
                        cout<<"Node inserted at the end!"<<endl;
                    }
                    else
                    {
                        n->next=ptr->next;
                        ptr->next=n;
                        cout<<"Node inserted in between!"<<endl;
                    }
                }
            }
        }

        // 5. Delete node by Unique Key
        void deleteNodeByKey(int k)
        {
            Node* ptr = nodeExists(k);
            if(ptr==NULL)
            {
                cout<<"No node exists with key value: "<<k<<endl;
            }
            else
            {
                if(ptr==head)
                {
                    if(head->next==head)
                    {
                        head=NULL;
                        cout<<"Head Node UNLINKED!...List Empty"<<endl;
                    }
                    else
                    {
                        Node* ptr = head;
                        while(ptr->next!=head) //Traverse the list to end
                        {
                            ptr = ptr->next;
                        }
                        //make the tail point to new head node
                        ptr->next = head->next;
                        head = head->next;
                        cout<<"Node UNLINKED with key: "<<k<<endl;
                    }
                }
                else //when Node to be deleted doesn't match the head node
                {
                    Node* temp = NULL;
                    Node* prevptr = head; //head address
                    Node* currentptr = head->next; //next address

                    //Traverse the linked list from head to the key in argument
                    while(currentptr!=NULL)
                    {
                        if(currentptr->key==k)
                        {
                            temp = currentptr;
                            currentptr = NULL;
                        }
                        else{
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }
                    }

                    if(temp!=NULL)
                    {
                        prevptr->next = temp->next;
                        cout<<"Node UNLINKED with keys value: "<<k<<endl;
                    }
                    else{
                        cout<<"Node doesn't exist with key value: "<<k<<endl;
                    }
                }
            }
        }

        // 6. Update Node
        void updateNodeByKey(int k, int d)
        {
            Node* ptr = nodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data=d;
                cout<<"Node Data updated successfully!"<<endl;
            }
            else{
                cout<<"Node doesn't exist with key value: "<<k<<endl;
            }
        }

        // 7. Print the linked list
        void print()
        {
            if(head==NULL)
            {
                cout<<"No nodes in Circular linked list"<<endl;
            }
            else
            {
                cout<<endl<<"Circular Linked list values: ";
                Node* temp = head;

                do
                {
                    cout<<" ("<<temp->key<<" , "<<temp->data<<" , "<<temp->next<<") --> ";
                    temp = temp->next;
                }while(temp!=head);
            }
        }

};

int main()
{
    CircularLinkedList c;
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
                c.appendNode(n1);
                break;
            case 2:
                cout<<"Prepend Node operation \n Enter key and data of the Node to be prepended."<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                c.prependNode(n1);
                break;
            case 3:
                cout<<"Insert Node operation \n Enter key of existing node after which you want to insert this new node: "<<endl;
                cin>>k1;
                cout<<"Enter key and data of the new node first: "<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                c.insertNodeAfter(k1,n1);
                break;
            case 4:
                cout<<"Delete Node By Key operation \n Enter key of Node to be deleted: "<<endl;
                cin>>k1;
                c.deleteNodeByKey(k1);
                break;
            case 5:
                cout<<"Update Node By Key operation \n Enter key & New Data to be updated: "<<endl;
                cin>>key1;
                cin>>data1;
                c.updateNodeByKey(key1, data1);
                break;
            case 6:
                c.print();
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