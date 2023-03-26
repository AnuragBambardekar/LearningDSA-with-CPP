# Add Two Linked Lists
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1: <br>

Input: l1 = [2,4,3], <br> l2 = [5,6,4] <br>
Output: [7,0,8] <br>
Explanation: 342 + 465 = 807. <br>

Example 2:

Input: l1 = [0], <br> l2 = [0] <br>
Output: [0] <br>

Example 3:

Input: l1 = [9,9,9,9,9,9,9], <br> l2 = [9,9,9,9] <br>
Output: [8,9,9,9,0,0,0,1] <br>
 

Constraints:

The number of nodes in each linked list is in the range [1, 100]. <br>
0 <= Node.val <= 9 <br>
It is guaranteed that the list represents a number that does not have leading zeros. <br>


```
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
        
    }
};
```
