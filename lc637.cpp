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
    vector<double> res;
    vector<double> averageOfLevels(TreeNode* root) {
        int sum,len;
        queue<TreeNode*> queue_tree;
        TreeNode* p;
        queue_tree.push(root);
        while(!queue_tree.empty()){
            sum = 0;
            len = queue_tree.size();
            for(int i=0;i<len;i++){
                p = queue_tree.front();
                queue_tree.pop();        
                sum+=(p->val);
                if(p->left) queue_tree.push(p->left);
                if(p->right) queue_tree.push(p->right);
            }
            res.push_back(sum/len); 
        }
        return res;
    }
};