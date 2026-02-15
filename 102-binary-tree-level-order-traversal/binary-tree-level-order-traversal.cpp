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
    void lvlbylvl(TreeNode *root,int currlvl,int maxlvl,vector<vector<int>> &ans,vector<int> &v){
        if(root==NULL) return ;
        if(maxlvl==currlvl) v.push_back(root->val);
        lvlbylvl(root->left,currlvl+1,maxlvl,ans,v);
        lvlbylvl(root->right,currlvl+1,maxlvl,ans,v);
    }
    void all(TreeNode * root, vector<vector<int>> &ans){
        for(int i =1;i<=lvl(root);i++){
            vector<int> v;
            lvlbylvl(root,1,i,ans,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        all(root,ans);
        return ans;
    }
};