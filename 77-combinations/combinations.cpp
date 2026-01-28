class Solution {
public:
void helper(vector<vector<int>> &ans,int start,int &n,int &k,vector<int> &v){
    if(v.size()==k){
        ans.push_back(v);
        return;
    }
    for(int i =start;i<=n;i++){
        v.push_back(i);
        helper(ans,i+1,n,k,v);
        v.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans,1,n,k,v);
        return ans;
    }
};