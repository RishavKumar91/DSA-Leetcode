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
    void hlpr(TreeNode *root,vector<string> &ans,string & s){
        if(root==NULL) return;
        int l = s.size();
        s += to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
        }
        else {
            s += "->";
            hlpr(root->left,ans,s);
            hlpr(root->right,ans,s);
        }
        s.resize(l);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        hlpr(root,ans,s);
        return ans;
    }
};