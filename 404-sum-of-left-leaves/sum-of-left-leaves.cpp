class Solution {
public:
    int hlpr(TreeNode* root,bool flag){
        if(!root) return 0;
        if(!root->left && !root->right && flag) return root->val;
        return hlpr(root->left,1) + hlpr(root->right,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return hlpr(root,0);
    }
};