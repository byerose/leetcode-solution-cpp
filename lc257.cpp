#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    void walk(TreeNode* root,vector<string>& paths,string path){
        if(root!=nullptr){
            path += to_string(root->val);
            if(root->left==nullptr && root->right==nullptr) paths.push_back(path);
            else{
                path += "->";
                walk(root->left,paths,path);
                walk(root->right,paths,path);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        walk(root,paths,"");
        return paths;
    }
};

class Solution2 {
public:
    void walk(TreeNode* root,vector<string>& paths){
        queue<TreeNode*> node_queue;
        queue<string> path_queue;
        string path;
        if(root==nullptr) return;
        node_queue.push(root);
        path_queue.push(to_string(root->val));
        while(!node_queue.empty()){
            TreeNode* node = node_queue.front();
            path = path_queue.front();
            node_queue.pop(),path_queue.pop();

            if(node->left==nullptr && node->right==nullptr)
                paths.push_back(path);
            else{
                if(node->left!=nullptr){
                    node_queue.push(node->left);
                    path_queue.push(path+"->"+to_string(node->left->val));
                }
                if(node->right!=nullptr){
                    node_queue.push(node->right);
                    path_queue.push(path+"->"+to_string(node->right->val));
                }
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        walk(root,paths);
        return paths;
    }
};


int main(){

}