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
    // Iterative Solution
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* current = root;

        while(current!=NULL || !s.empty()){ // runs till stack is empty or current element is NULL
            while(current!=NULL){
                s.push(current); // push the element in stack
                current = current->left; // traverse the left tree first
            }

            current = s.top(); // returns first element in the stack
            s.pop(); // removes the first element from the stack
            ans.push_back(current->val); // store the results in tne 'ans' vector

            current = current->right; // then, traverse the right tree
        }
        return ans;
    }
};

int main() {

    // //TEST CASE 1
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create an instance of the Solution class
    Solution solution;

    // Call the inorderTraversal method
    vector<int> result = solution.inorderTraversal(root);

    // Print out the resulting vector
    cout << "Inorder traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
