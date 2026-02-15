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
    void hlpr(TreeNode* root,int now, int &targetSum,bool &flag){
        if(!root) return;
        now+=root->val;
        if(!root->left && !root->right && now == targetSum) flag =1;
        hlpr(root->left,now,targetSum,flag);
        hlpr(root->right,now,targetSum,flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int sum = 0;
        bool flag = 0;
        hlpr(root,0,targetSum,flag);
        return flag;

    }
};