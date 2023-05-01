# isSameTree
Given the roots of two binary trees p and q, write a function to check if they are the same or not. <br>
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value. <br>
 
**Example 1:** <br>
 
Input: p = [1,2,3], q = [1,2,3] <br>
Output: true <br>

**Example 2:** <br>
 
Input: p = [1,2], q = [1,null,2] <br>
Output: false <br>

**Example 3:** <br>
 
Input: p = [1,2,1], q = [1,1,2] <br>
Output: false <br>

 
**Constraints:**
●	The number of nodes in both trees is in the range [0, 100]. <br>
●	-104 <= Node.val <= 104 <br>

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
    }
};
```