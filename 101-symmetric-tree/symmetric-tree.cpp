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
    bool mirror(TreeNode *lft,TreeNode *rgt){
        if(!lft && !rgt) return 1;
        if(!lft || !rgt) return 0;
        if(lft->val != rgt->val) return 0;
        return (mirror(lft->left,rgt->right) &&  mirror(lft->right,rgt->left) ); 
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root->left ,root->right);
    }
};