#include<iostream>
#include<vector>
#include<unordered_set>

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
    vector<TreeNode*> res;
    unordered_set<int> del_set;
    TreeNode* del(TreeNode* root){
        if(!root) return nullptr;
        root->left = del(root->left); //取删除后的左子树
        root->right = del(root->right); //取删除后的右子树
        if(del_set.count(root->val)){ //处理当前节点
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            root = nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto& x:to_delete) del_set.insert(x);
        TreeNode* p = del(root);
        if(p) res.push_back(p);
        return res;
    }
};