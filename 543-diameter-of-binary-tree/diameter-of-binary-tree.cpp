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
    return 1 + max(lvl(root->left),lvl(root->right)) ;
}
void helper(int &D,TreeNode * root){
    if(root==NULL) return ;
    D = max(D,(lvl(root->left)+lvl(root->right)));
    helper(D,root->left);
    helper(D,root->right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
    helper(d,root);
        return d;
    }
};