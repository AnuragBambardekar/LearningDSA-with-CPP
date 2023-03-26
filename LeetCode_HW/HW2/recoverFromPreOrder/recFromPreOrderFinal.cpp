#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

// function to print binary tree in level-order traversal
void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);
    vector<int> levelOrder;

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                levelOrder.push_back(INT_MAX);
                continue;
            }

            levelOrder.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
    }

    // Print the level-order traversal in the desired format
    cout << "[";
    int lastNonNullIndex = levelOrder.size() - 1;
    while (levelOrder[lastNonNullIndex] == INT_MAX) {
        lastNonNullIndex--;
    }
    for (int i = 0; i <= lastNonNullIndex; i++) {
        if (levelOrder[i] == INT_MAX) {
            cout << "null";
        } else {
            cout << levelOrder[i];
        }

        if (i != lastNonNullIndex) {
            cout << ",";
        }
    }
    cout << "]" << endl;
};

/**
This function printLevelOrder prints the binary tree in level-order traversal. It takes a TreeNode* argument, which is the root of the binary tree. 
If the root is null, the function simply returns without printing anything.

The function uses a queue<TreeNode*> and a vector<int> to store the nodes in level-order traversal. It first pushes the root node onto the queue, and then 
iteratively removes each node from the front of the queue, pushes its value onto the levelOrder vector, and pushes its left and right children onto the queue 
(if they exist). If a node is null, it adds INT_MAX to the levelOrder vector instead of the null node.

After completing the level-order traversal, the function prints the levelOrder vector in the desired format, which is a comma-separated list of values enclosed 
in square brackets. If a value is INT_MAX, it prints "null" instead.
*/

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        // define a stack of treenodes we have visited
        stack<TreeNode*> st;

        // i is the current index in the traversal string
        // n is the length of the string
        int i = 0, n = traversal.length();

        // iterate over traversal-string to calculate depth of tree
        while (i < n) {
            int level = 0;
            while (i < n && traversal[i] == '-') {
                level++; // increment the level counter when '-' is found in string
                i++;
            }

            // now that we have level, we find out the value (retrieve the digit from the input string)
            int val = 0;
            // checks if the current character in the traversal string is a digit from 0 to 9
            while (i < n && traversal[i] >= '0' && traversal[i] <= '9') {
                val = val * 10 + (traversal[i] - '0'); // convert to int
                i++;
            }

            // create a new node, now that we have a level and value to be inserted
            TreeNode* node = new TreeNode(val);

            // if level of new node is equal to stack size, add it as left child of parent node
            if (level == st.size()) {
                if (!st.empty()) {
                    st.top()->left = node;
                }
            } else { 
                // if level is greater than size of stack, pop nodes from stack until level is 
                // equal to size of stack, then add the new node to right
                while (level != st.size()) {
                    st.pop();
                }
                st.top()->right = node;
            }
            st.push(node);
        }

        while (st.size() > 1) {
            st.pop();
        }
        cout<<st.top()->val<<endl;
        return st.top();
    }
};



int main() {
    
    Solution s;
    TreeNode* root = s.recoverFromPreorder("1-2--3---4-5--6---7");
    // TreeNode* root = s.recoverFromPreorder("1-2--3--4-5--6--7");
    printLevelOrder(root);

    return 0;
}

