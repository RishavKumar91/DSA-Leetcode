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
int ans = 0 ;
    void hlpr(TreeNode *root , long long t){
        
        if(!root) return ;
        t = t-root->val;
        if(t == 0){
            ans++;
        }
        hlpr(root->left , t);
        hlpr(root->right,t);
    }
    int pathSum(TreeNode* root, int ta) {
        if(!root) return 0;
        long long t = 0LL + ta;
        hlpr(root , t);
        pathSum(root->left , t);
        pathSum(root->right , t );
        return ans ;
    }
};