#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0); // create dummy node 0
        int carry = 0;

        ListNode* head = l3;

        while(l1 && l2)
        {
            int value = l1->val + l2->val + carry;
            carry = value/10;
            l3->next = new ListNode(value%10);
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            int value = l1->val + carry;
            carry = value/10;
            l3->next = new ListNode(value%10);
            l3 = l3->next;
            l1 = l1->next;
        }

         while(l2)
        {
            int value = l2->val + carry;
            carry = value/10;
            l3->next = new ListNode(value%10);
            l3 = l3->next;
            l2 = l2->next;
        }

        if(carry)
        {
            l3->next = new ListNode(carry);
        }

        return head->next;
    }
};

int main() {

    //TEST CASE 1
    /* ListNode *A = new ListNode(3);
    A->next = new ListNode(6);
    A->next->next = new ListNode(7);
    A->next->next->next = new ListNode(2);
    A->next->next->next->next = new ListNode(5);

    ListNode *B = new ListNode(2);
    B->next = new ListNode(8);
    B->next->next = new ListNode(4);
    B->next->next->next = new ListNode(9); */

    //TEST CASE 2
    ListNode *A = new ListNode(9);
    A->next = new ListNode(9);
    A->next->next = new ListNode(9);
    A->next->next->next = new ListNode(9);
    A->next->next->next->next = new ListNode(9);
    A->next->next->next->next->next = new ListNode(9);
    A->next->next->next->next->next = new ListNode(9);

    ListNode *B = new ListNode(9);
    B->next = new ListNode(9);
    B->next->next = new ListNode(9);
    B->next->next->next = new ListNode(9);

    Solution sol;
    ListNode *result = sol.addTwoNumbers(A, B);

    cout<<"Resultant list is: ";
    while (result != NULL) {
        cout<<result->val<<" ";
        //cout << result->val << " -> ";
        result = result->next;
    }
    //cout << "NULL" << endl;
    return 0;
}
