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
    void h(TreeNode *p,TreeNode *q,bool &ans){
        if(ans ==0) return;
        if(p==NULL && q!=NULL) {ans =0 ;return ;}
        if(p!=NULL && q==NULL) {ans =0;return ;}
        if(p==NULL && q==NULL) {return ;}
        if(p->val!=q->val) {ans =0; return ;}
        h(p->left,q->left,ans);
        h(p->right,q->right,ans);
        return ;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans =1;
        h(p,q,ans);
        return ans;
    }
};