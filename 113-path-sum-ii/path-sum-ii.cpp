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
    vector<vector<int>> ans ;
    void hlpr(TreeNode* root , int t , vector<int> &v ){
        if(!root){
            // if(t==0) ans.push_back(v);
            return ;
        }
        if(!root->left && !root->right){
            if(root->val == t) {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
                }
            return ;
        }
        v.push_back(root->val);
        hlpr(root->left,t-root->val,v);
        v.pop_back();

        v.push_back(root->val);
        hlpr(root->right,t-root->val,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        vector<int> v;
        hlpr(root , targetSum , v);
        return ans;
    }
};