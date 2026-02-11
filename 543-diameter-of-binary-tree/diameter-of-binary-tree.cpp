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
int maxDia = 0;
    int lvl(TreeNode *root){
        if(root==NULL) return 0;
        int lft = lvl(root->left);
        int right = lvl(root->right);
        maxDia = max(maxDia,lft+right);
        return 1 + max(lft,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        lvl(root);
    return maxDia;
    }
};