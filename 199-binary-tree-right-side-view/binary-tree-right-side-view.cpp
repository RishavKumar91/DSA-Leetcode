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
vector<int> ans;
    int lvl(TreeNode * root){
        if(root==NULL) return 0;
        return 1 + max(lvl(root->left),lvl(root->right));
    }
    void hlpr(vector<int> &ans,TreeNode *root,int x){
        if(!root) return;
        ans[x] = root->val;
        hlpr(ans,root->left,x+1);
        hlpr(ans,root->right,x+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        int t = lvl(root);
        vector<int> ans(t);
        hlpr(ans,root,0);
        return ans;
    }
};