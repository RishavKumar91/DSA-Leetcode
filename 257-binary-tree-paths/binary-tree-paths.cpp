/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void hlpr(TreeNode * root,vector<string> &ans,string s){
        if (!s.empty()) s += "->";
        s += to_string(root->val);
        if(root->left)  hlpr(root->left,ans,s);
        if(root->right) hlpr(root->right,ans,s);
        if(!root->left && !root->right) ans.push_back(s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        hlpr(root,ans,s);
        return ans;
    }
};