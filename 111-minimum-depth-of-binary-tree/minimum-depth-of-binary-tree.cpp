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
        if(!root) return 0;
        if(!root->left) return 1 + lvl(root->right);
        if(!root->right) return 1 + lvl(root->left);
        int a = lvl(root->left);
        int b = lvl(root->right);

        return 1 + min(a, b);
        return 1 + min(lvl(root->left) , lvl(root->right));
    }
    int minDepth(TreeNode* root) {
        return lvl(root);
    }
};