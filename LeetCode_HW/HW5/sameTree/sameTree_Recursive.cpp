#include <iostream>
#include <vector>
#include <queue>
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
      bool isSameTree(TreeNode* p, TreeNode* q) {
          if(p==nullptr && q==nullptr) return true;
          if(p==nullptr || q==nullptr) return false;
          if(q->val!=p->val) return false;
          return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
      }
  };

  int main() {
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Solution solution;

    if (solution.isSameTree(p, q))
        cout<< "true"<<endl;
    else
        cout<< "false"<<endl;

    return 0;
}