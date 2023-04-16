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
    ListNode* sortList(ListNode* head)  {
        // check if input has only one node or it is null
        if (!head || !head->next) {
            return head;
        }
        
        // Finding the middle node of the linked list
        ListNode *slow = head, *fast = head->next; // use 2 ptrs= fast and slow

        while (fast && fast->next) {
            slow = slow->next; //slow points to first node initially
            fast = fast->next->next; // fast points to second node initially
        }
        ListNode* mid = slow->next;
        slow->next = nullptr; // middle found, so split at next node by adding nullptr
        
        // Recursively sorting the two halves of the linked list
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        // Merging the two sorted halves of the linked list
        ListNode res(0);
        ListNode* tail = &res; // points to res node
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        //  linking the remaining nodes to the next pointer of the tail node
        tail->next = left ? left : right;
        
        return res.next;
    }
};

int main() {

    Solution solution;
    
    // Test case 1
    ListNode* head1 = new ListNode(4);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(1);
    head1->next->next->next = new ListNode(3);
    ListNode* sorted1 = solution.sortList(head1);
    std::cout << "Sorted list: ";
    while (sorted1) {
        std::cout << sorted1->val << " ";
        sorted1 = sorted1->next;
    }
    std::cout << std::endl;

    // Test case 2
    ListNode* head2 = new ListNode(-1);
    head2->next = new ListNode(5);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(0);
    ListNode* sorted2 = solution.sortList(head2);
    std::cout << "Sorted list: ";
    while (sorted2) {
        std::cout << sorted2->val << " ";
        sorted2 = sorted2->next;
    }
    std::cout << std::endl;
    return 0;
}
