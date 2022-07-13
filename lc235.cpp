#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val) swap(p,q);
        while(!(p->val<=root->val && root->val<=q->val)){
            if(q->val<root->val) root = root->left;
            if(root->val<p->val) root = root->right;
        }        
        return root;
    }
};