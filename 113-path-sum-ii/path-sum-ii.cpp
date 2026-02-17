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
    void hlpr(TreeNode * root,vector<vector<int>> &ans,int now,int &targetSum,vector<int> v){
        if(root==NULL ) return;
        if(!root->left && !root->right){
            now+=root->val;
            v.push_back(root->val);
            if(now == targetSum){
               ans.push_back(v);
               return ;
            }
        }
        now+=root->val;
        v.push_back(root->val);
        hlpr(root->left,ans,now,targetSum,v);
        hlpr(root->right,ans,now,targetSum,v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        hlpr(root,ans,0,targetSum,v);
        return ans;
    }
};