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
int lvl(TreeNode * root){
    if(!root) return 0;
    return 1 + max(lvl(root->right),lvl(root->left));
}

void hlpr(TreeNode * root,vector<vector<int>> & ans,int &n){
    if(root==NULL) return;
    queue<TreeNode*> q;
    int ix = 0;
    q.push(root);
    while(!q.empty()){
        int c = q.size();
        vector<int> v;
        for(int i =0;i<c;i++){
            v.push_back(q.front()->val);
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
    ans[n-ix-1] = v;
    ix++;
    }
}
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        int n = lvl(root);
        vector<vector<int>> ans(n);
        hlpr(root,ans,n);
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};