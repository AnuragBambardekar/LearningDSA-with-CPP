#include <iostream>

struct Node {
  int data;
  Node *next;
};

class LinkedList {
 public:
  LinkedList() : head(NULL) {}

  void insertAtHead(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
  }

  void insertAtTail(int data) {
    if (head == NULL) {
      head = new Node();
      head->data = data;
      head->next = NULL;
    } else {
      Node *newNode = new Node();
      newNode->data = data;
      newNode->next = NULL;
      Node *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void deleteNode(int data) {
    if (head == NULL) {
      return;
    }
    if (head->data == data) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != data) {
      temp = temp->next;
    }
    if (temp->next == NULL) {
      return;
    }
    Node *toBeDeleted = temp->next;
    temp->next = toBeDeleted->next;
    delete toBeDeleted;
  }

  void printList() {
    Node *temp = head;
    while (temp != NULL) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }

 private:
  Node *head;
};

int main() {
  LinkedList linkedList;
  linkedList.insertAtHead(5);
  linkedList.printList();
  linkedList.insertAtHead(10);
  linkedList.printList();
  linkedList.insertAtTail(15);
  linkedList.printList();
  linkedList.insertAtTail(20);
  linkedList.printList();
  linkedList.deleteNode(10);
  linkedList.printList();
  return 0;
}
