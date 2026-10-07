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
int ans ; 
    void hlpr(TreeNode* root, long long t){
        if(!root) return ;
        t -= root->val;
        if(t == 0) ans++;
        hlpr(root->left,t);
        hlpr(root->right,t);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return NULL;
        long long t = targetSum;
        hlpr(root,t);
        pathSum(root->left,t);
        pathSum(root->right,t);
    return ans;
    }
};