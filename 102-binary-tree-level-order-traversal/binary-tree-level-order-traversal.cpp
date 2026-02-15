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
    int lvl(TreeNode *root){
        if(root==NULL) return 0;
        return 1 + max(lvl(root->right),lvl(root->left));
    }
    void all(TreeNode *root,vector<vector<int>> &ans,int currlvl){
        if(root==NULL) return ;
        ans[currlvl].push_back(root->val);
        all(root->left,ans,currlvl+1);
        all(root->right,ans,currlvl+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans(lvl(root));
        all(root,ans,0);
        return ans;
    }
};