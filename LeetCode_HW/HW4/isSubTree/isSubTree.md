# isSubTree
## Problem Description
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
 
**Example 1:** <br>
 
Input: root = [3,4,5,1,2], subRoot = [4,1,2] <br>
Output: true <br>

**Example 2:** <br>
 
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2] <br>
Output: false <br>

 
**Constraints:** <br>
●	The number of nodes in the root tree is in the range [1, 2000]. <br>
●	The number of nodes in the subRoot tree is in the range [1, 1000]. <br>
●	-104 <= root.val <= 104 <br>
●	-104 <= subRoot.val <= 104 <br>

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
    }
};
```