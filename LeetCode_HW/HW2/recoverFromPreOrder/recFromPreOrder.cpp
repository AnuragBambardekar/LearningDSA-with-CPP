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
        stack<TreeNode*>stk;
        for(int i=0; i<traversal.length();){
            int level = 0;
            while(traversal[i]=='-'){
                level++;
                i++;
            }
            int start = i;
            while(isdigit(traversal[i])){
                i++;
            }
            int val = stoi(traversal.substr(start, i-start+1));
            cout<<val<<" Level is: "<<level<<endl;
        }
        return nullptr; 
    }
};

int main() {
    
    Solution s;
    s.recoverFromPreorder("1-2--3--4-5--6--7");


    return 0;
}
