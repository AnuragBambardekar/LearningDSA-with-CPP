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
        int n = traversal.size(); //get size of string
        if(n==0)
            return NULL; //Null tree
        
        vector<pair<TreeNode*, int>> v;

        //calculate depth
        int level=0, i=0;
        while(i<n) {
            int node_val=0;
            while(i<n && traversal[i]!='-') {
                node_val = 10 * node_val + (traversal[i]-'0');
                i++;
            }

            TreeNode *newNode = new TreeNode(node_val);

            //populate vector with node pointer and depth
            v.push_back(make_pair(newNode, level));

            //get the level - count number of dashes
            level = 0;
            while(i<n && traversal[i]=='-'){
                level++;
                i++;
            }
        }

        //iterate through the vector to construct BST
        for(i=1; i<v.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(v[i].second > v[j].second) {
                    //check if v[j] has left child/right child or not
                    if(v[j].first->left)
                        v[j].first->left = v[i].first;
                    else
                        v[j].first->right = v[i].first;
                    break;
                }
            }
        }

        //root node will be the first vector, so return it
        cout<<v[0].first->val;
        return v[0].first;
    }
};

int main() {
    
    Solution s;
    s.recoverFromPreorder("1-2--3--4-5--6--7");

    return 0;
}
