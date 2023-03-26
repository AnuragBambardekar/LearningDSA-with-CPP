# Merge and Sort the Array of Linked Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]] <br>
Output: [1,1,2,3,4,4,5,6] <br>
Explanation: <br> The linked-lists are: <br>
[
  1->4->5,
  1->3->4,
  2->6
] <br>
merging them into one sorted list: <br>
1->1->2->3->4->4->5->6 <br>

Example 2:

Input: lists = [] <br>
Output: [] <br>

Example 3:

Input: lists = [[]] <br>
Output: [] <br>
 

Constraints:

k == lists.length <br>
0 <= k <= 10^4 <br>
0 <= lists[i].length <= 500 <br>
-10^4 <= lists[i][j] <= 10^4 <br>
lists[i] is sorted in ascending order. <br>
The sum of lists[i].length won't exceed 10^4. <br>


```
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    }
};
```