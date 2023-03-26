#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
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
    string smallestFromLeaf(TreeNode* root) {
        string str, result;
        DFS(root, str, result);
        return result;
    }
    
    void DFS(TreeNode* root, string& str, string &result)
    {
        str.push_back(root->val + 'a');
        if (root->left == nullptr && root->right == nullptr)
        {
            string rev_str = str;
            std::reverse(rev_str.begin(), rev_str.end());
            if (result.empty()) result = rev_str;
            else result = min(rev_str, result);
        }
        else
        {
            if (root->left != nullptr)
            {
                DFS(root->left, str, result);
            }
            if (root->right != nullptr)
            {
                DFS(root->right, str, result);
            }
        }
        str.pop_back();
    }
    
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    Solution solution;
    string result = solution.smallestFromLeaf(root);

    cout << "Smallest string from leaf: " << result << endl;
    return 0;
}