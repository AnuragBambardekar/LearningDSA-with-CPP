#include <iostream>
using namespace std;

//Node Class
class Node{
    public:
        int key;
        int data;
        Node* next; //Class pointer

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

//Singly Linked List Class
class SinglyLinkedList{
    public:
        Node* head;

        //Default constructor
        SinglyLinkedList()
        {
            head = NULL;
        }

        //Parameterized constructor
        SinglyLinkedList(Node *n) //pass by address
        {
            head = n; //head points to 1st node
        }

        // 1. Check if the node exists
        //refer image in folder: ChecknodeExists.png
        Node* nodeExists(int k) //method which returns a pointer, pass the key value of the node
        {
            //traverse through singly linked list to check if key=k exists
            Node* temp = NULL;
            Node* ptr = head; //use ptr to traverse list

            while(ptr!=NULL)
            {
                if(ptr->key == k)
                {
                    temp=ptr; //key exists in the linked list, so store it in temp
                }
                ptr = ptr->next; //point to next node
            }
            return temp; //if no match, then temp = NULL
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
                    cout<<"Node Appended!"<<endl;
                }
                else //head pointer is pointing to some other node, there are other nodes in singly linked list
                {
                    Node* ptr = head; //address of head node stored in ptr
                    while(ptr->next!=NULL) //traverse the linked list, till we reach tail
                    {
                        ptr = ptr->next; //next node, we are incrementing basically to next node
                    }
                    ptr->next = n; //Append the node at the end of the linked list.
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
            else{
                //when no node attached in singly linked list
                if(head == NULL) //when node is not pointing to any nodes
                {
                    head = n;
                    cout<<"Node Appended!"<<endl;
                }
                else //head pointer is pointing to some other node, there are other nodes in singly linked list
                {
                    //Now, no need to traverse the linked list
                    //Example: n4 next address points to n1
                    n->next=head; //next address of new node is equal to address of head.
                    head = n; //make n4 the head, since it was prepended to earlier head(n1).
                    cout<<"Node Prepended!"<<endl;
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
                    //our pointer is pointing at n2
                    //n is n4, ptr is n2
                    n->next = ptr->next; //n2's next address is stored in n4's next address
                    ptr->next = n;
                    cout<<"Node Inserted! "<<endl;
                }
            }
        }

        // 5. Delete node by Unique Key
        void deleteNodeByKey(int k)
        {
            if(head == NULL)
            {
                //no node attached yet
                cout<<"Singly Linked List already Empty, Cannot Delete!"<<endl;
            }
            else if(head!=NULL)
            {
                if(head->key == k)
                {
                    //unlink the head node itself (n1)
                    head = head->next; //head is now having address of next address(n2)
                    cout<<"Node UNLINKED with keys value: "<<k<<endl;
                }
                else //delete node which is not head (anything in between)
                {
                    Node* temp = NULL;
                    Node* prevptr = head;
                    Node* currentptr = head->next;
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
                cout<<"No nodes in Singly linked list"<<endl;
            }
            else
            {
                cout<<endl<<"Singly Linked list values: ";
                Node* temp = head;

                while(temp != NULL)
                {
                    cout<<" ("<<temp->key<<" , "<<temp->data<<") --> ";
                    temp = temp->next;
                }
            }
        }


};

int main()
{
    SinglyLinkedList s;
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
                s.appendNode(n1);
                break;
            case 2:
                cout<<"Prepend Node operation \n Enter key and data of the Node to be prepended."<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                s.prependNode(n1);
                break;
            case 3:
                cout<<"Insert Node operation \n Enter key of existing node after which you want to insert this new node: "<<endl;
                cin>>k1;
                cout<<"Enter key and data of the new node first: "<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                s.insertNodeAfter(k1,n1);
                break;
            case 4:
                cout<<"Delete Node By Key operation \n Enter key of Node to be deleted: "<<endl;
                cin>>k1;
                s.deleteNodeByKey(k1);
                break;
            case 5:
                cout<<"Update Node By Key operation \n Enter key o& New Data to be updated: "<<endl;
                cin>>key1;
                cin>>data1;
                s.updateNodeByKey(key1, data1);
                break;
            case 6:
                s.print();
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