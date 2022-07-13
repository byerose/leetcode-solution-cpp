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
    TreeNode* tmp;
    bool findVal(TreeNode* root,int x){
        if(!root) return false;
        if(root->val==x) return true;
        return findVal(root->left,x) || findVal(root->right,x);
    }
    bool findNext(TreeNode* root,int k){
        if(!root) return false;
        if(findVal(tmp,k-root->val)&&k-root->val!=root->val) return true;
        return findNext(root->left,k) || findNext(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        tmp = root;
        return findNext(root,k);
    }
};