#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution solution;

    // Example 1
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);

    TreeNode *subRoot1 = new TreeNode(4);
    subRoot1->left = new TreeNode(1);
    subRoot1->right = new TreeNode(2);

    bool result1 = solution.isSubtree(root1, subRoot1);
    if (result1 == 1) {
            cout << "Example 1: "<< "true" << endl;
        } else {
            cout << "Example 1: "<< "false" << endl;
        }
    // cout << "Example 1: " << result1 << endl;

    // Example 2
    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(2);
    root2->left->right->left = new TreeNode(0);

    TreeNode *subRoot2 = new TreeNode(4);
    subRoot2->left = new TreeNode(1);
    subRoot2->right = new TreeNode(2);

    bool result2 = solution.isSubtree(root2, subRoot2);
    if (result2 == 1) {
            cout << "Example 2: "<< "true" << endl;
        } else {
            cout << "Example 2: "<< "false" << endl;
        }
    // cout << "Example 2: " << result2 << endl;

    return 0;
}