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
    bool searchTree(TreeNode* root,TreeNode* x){
        if(!root) return false;
        if(root==x) return true;
        return searchTree(root->left,x) || searchTree(root->right,x);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(searchTree(root->left,p)&&searchTree(root->left,q)){
                root = root->left;
            }
            else if(searchTree(root->right,p)&&searchTree(root->right,q)){
                root = root->right;
            }else{
                return root;
            }
        }
        return nullptr;
    }
};