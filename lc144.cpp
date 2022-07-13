#include<iostream>
#include<vector>

using namespace std;

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
    vector<int> res;
    void travel(TreeNode* root){
        if(!root) return;res.push_back(root->val);
        if(root->left) travel(root->left);
        if(root->right) travel(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        travel(root);
        return res;
    }
};