#include <iostream>
#include <vector>
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
    void inorder(TreeNode* root, vector<int> &bst) {
        if(root == NULL){
            return;
        }
        inorder(root->left, bst);
        bst.push_back(root->val);
        inorder(root->right, bst);
    }
    bool isValidBST(TreeNode* root) {
        int flag = 0;
        if(root == NULL)
        {
            return true;
        }

        vector<int> bst;
        inorder(root, bst);

        for(int i=0; i<bst.size()-1; i++)
        {
            if(bst[i] >= bst[i+1]){
                flag++;
            }
        }

        if(flag==0){
            return true;
        } else {
            return false;
        }
    }

    
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);

    // Check if the binary tree is a valid binary search tree
    Solution s;
    if (s.isValidBST(root)) {
        cout << "The binary tree is a valid binary search tree." << endl;
    } else {
        cout << "The binary tree is not a valid binary search tree." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
