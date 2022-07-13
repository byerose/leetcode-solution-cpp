#include<iostream>
#include<vector>
#include<algorithm>

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
    vector<TreeNode*> node_list;
    static bool cmp(TreeNode* p1,TreeNode* p2){
        return p1->val<=p2->val;
    }
    void traval(TreeNode* root){
        if(!root) return;
        traval(root->left);
        node_list.push_back(root);
        traval(root->right);
    }    
    void recoverTree(TreeNode* root) {
        traval(root);
        sort(node_list.begin(),node_list.end(),cmp);
        for(auto& x:node_list){
            cout<<x->val;
        }
    }
};