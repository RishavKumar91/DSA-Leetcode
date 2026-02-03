/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool exists(TreeNode *target,TreeNode *root){
        if(root==NULL) return 0;
        if(root==target) return 1;
        return (exists(target,root->left) || exists(target,root->right));
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(exists(p,root->left) && exists(q,root->left)) 
        return lowestCommonAncestor(root->left,p,q);
        else if(exists(p,root->right) && exists(q,root->right)) 
        return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};