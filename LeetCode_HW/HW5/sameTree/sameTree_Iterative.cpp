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
        queue<TreeNode *> queue;
        queue.push(p);
        queue.push(q);
        while (queue.size()!=0){
            TreeNode * q2=queue.front();
            queue.pop();
            TreeNode * q1=queue.front();
            queue.pop();
            if (q1==nullptr && q2==nullptr) continue;
            if (q1==nullptr || q2==nullptr) return false;
            if (q1->val!=q2->val) return false;
            queue.push(q1->left);
            queue.push(q2->left);
            queue.push(q1->right);
            queue.push(q2->right);
        }
        return true;
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
