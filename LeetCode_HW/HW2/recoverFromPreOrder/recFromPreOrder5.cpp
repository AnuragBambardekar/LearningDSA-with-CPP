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

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        // define a stack of treenodes we have visited
        stack<TreeNode*> st;

        // i is the current index in the traversal string
        // n is the length of the string
        int i = 0, n = traversal.length();

        // iterate over traversal string to calculate depth
        while (i < n) {
            int level = 0;
            while (i < n && traversal[i] == '-') {
                level++; // increment the level counter when '-' is found in string
                i++;
            }

            int val = 0;
            // checks if the current character in the traversal string is a digit from 0 to 9
            while (i < n && traversal[i] >= '0' && traversal[i] <= '9') {
                val = val * 10 + (traversal[i] - '0'); // convert to int
                i++;
            }

            // create a new node
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

// // function to print binary tree in level-order traversal
// void printLevelOrder(TreeNode* root)
// {
//     if (root == NULL) return;

//     // create an empty queue for level-order traversal
//     queue<TreeNode*> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         int n = q.size();

//         // print all nodes at the current level
//         for (int i = 0; i < n; i++)
//         {
//             TreeNode* node = q.front();
//             q.pop();

//             if (node == NULL) {
//                 cout << "null ";
//                 continue;
//             }

//             cout << node->val << " ";
//             q.push(node->left);
//             q.push(node->right);
//         }

//         // add a new line after each level
//         cout << endl;
//     }
// }

// void printLevelOrder(TreeNode* root) {
//     if (root == NULL) return;

//     queue<TreeNode*> q;
//     q.push(root);
//     vector<int> levelOrder;

//     while (!q.empty()) {
//         int n = q.size();

//         for (int i = 0; i < n; i++) {
//             TreeNode* node = q.front();
//             q.pop();

//             if (node == NULL) {
//                 levelOrder.push_back(INT_MAX);
//                 continue;
//             }

//             levelOrder.push_back(node->val);
//             q.push(node->left);
//             q.push(node->right);
//         }
//     }
//     // Print the level-order traversal in the desired format
//     cout << "[";
//     for (int i = 0; i < levelOrder.size(); i++) {
//         if (levelOrder[i] == INT_MAX) { //used to check if a node value is NULL in the level-order traversal.
//             cout << "null";
//         } else {
//             cout << levelOrder[i];
//         }

//         if (i != levelOrder.size() - 1) {
//             cout << ",";
//         }
//     }
//     cout << "]" << endl;
// }

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
}

int main() {
    
    Solution s;
    TreeNode* root = s.recoverFromPreorder("1-2--3---4-5--6---7");
    // TreeNode* root = s.recoverFromPreorder("1-2--3--4-5--6--7");
    printLevelOrder(root);

    return 0;
}

