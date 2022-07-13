#include<iostream>

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

    int sumOfLeft(TreeNode* root,int flag) {
        if(!root) return 0;
        if(!root->left&&!root->right&&flag) return root->val;
        return sumOfLeft(root->left,1)+sumOfLeft(root->right,0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeft(root,0);
    }
};