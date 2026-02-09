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
    void fill(TreeNode * root , vector<int> &v){
        if(!root) return;
        fill(root->left,v);
        v.push_back(root->val);
        fill(root->right,v);
    }
    TreeNode * make(int l,int r ,vector<int> &v){
        if(l>r) return NULL;
        int m = l+(r-l)/2;
        TreeNode * root = new TreeNode(v[m]);
        root->left = make(l,m-1,v);
        root->right = make(m+1,r,v);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        fill(root,v);
        TreeNode * neww = make(0,v.size()-1,v);
        return neww;
    }
};