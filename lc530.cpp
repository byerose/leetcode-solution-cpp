#include<iostream>
#include<cmath>

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
    int pre,p,min_val=0;
    void traval(TreeNode* root){
        if(root->left) traval(root->left);
        if(!min_val)
            min_val = abs(root->val-pre);
        else
            min_val = min(min_val,abs(root->val-pre));
        pre = root->val;
        if(root->right) traval(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        TreeNode* p = root;
        while(p->left){
            p=p->left;
        }
        pre = p->val;
        traval(root);
        return min_val;
    }
};