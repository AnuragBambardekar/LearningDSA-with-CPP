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
        cout<<st.top()->val;
        return st.top();
    }
};

int main() {
    
    Solution s;
    // s.recoverFromPreorder("1-2--3--4-5--6--7");
    s.recoverFromPreorder("1-2--3---4-5--6--7");

    return 0;
}


/**
 * To construct a binary tree from the given preorder traversal, we can use recursion. 
 * At each node, we check its depth and compare it with the depth of the previous node. 
 * If the depth of the current node is greater than the depth of the previous node, we create a new node and add it as the left child of the previous node.
 * If the depth of the current node is the same as the depth of the previous node, we add the new node as the right child of the parent of the previous node. 
 * We also keep track of the previous node to handle the cases where the depth of the current node is less than the depth of the previous node.
 * 
*/