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
int ans = 0;
void dfs(TreeNode* root,string s,vector<string> &ans){
    if(root==NULL) return ;
    if(root->left==NULL && root->right==NULL) {
        char ch = root->val + '0';
        s.push_back(ch);
        ans.push_back(s);
        return ;
    }
    char ch = root->val + '0';
    s.push_back(ch);
    dfs(root->left,s,ans);
    dfs(root->right,s,ans);

}
    int sumRootToLeaf(TreeNode* root) {
        string s="";
        int ans = 0;
        vector<string> str;
        dfs(root,s,str);
        for(int i =0;i<str.size();i++){
            int a = 1;
            string sss = str[i];
            for(int j =sss.size()-1;j>=0;j--){
                if(sss[j]=='1') ans +=a;
                a*=2;
            }
        }
        return ans;
    }
};