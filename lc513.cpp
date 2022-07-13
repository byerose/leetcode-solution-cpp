#include<iostream>
#include<queue>

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
    queue<TreeNode*> queue_tree;
    int findBottomLeftValue(TreeNode* root) {
        queue_tree.push(root);
        TreeNode* p,* res;
        while(!queue_tree.empty()){
            for(int i=0;i<queue_tree.size();i++){
                p = queue_tree.front();
                if(i==0) res = p;
                queue_tree.pop();
                cout<<p->val;
                if(p->left) queue_tree.push(p->left);
                if(p->right) queue_tree.push(p->right);
            }
        }
        return res->val;
    }
};