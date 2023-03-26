# In Order Tree Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1: <br>
Input: root = [1,null,2,3] <br>
Output: [1,3,2] <br>

Example 2: <br>
Input: root = [] <br>
Output: [] <br>

Example 3: <br>
Input: root = [1] <br>
Output: [1] <br>

**Constraints:**

The number of nodes in the tree is in the range [0, 100]. <br>
-100 <= Node.val <= 100 <br>



```cpp
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
    vector<int> inorderTraversal(TreeNode* root) {
        
    }
};```


Follow up: Recursive solution is trivial, could you do it iteratively?
