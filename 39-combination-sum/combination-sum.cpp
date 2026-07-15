class Solution {
public:
vector<vector<int>> ans;
int n;
void hlpr(vector<int> &c , int tar,int ix,vector<int> &v){
    if(ix>=n) return ;
    if(tar<0) return;
    if(tar==0) { ans.push_back(v); return ;}
    hlpr(c,tar,ix+1,v);
    v.push_back(c[ix]);
    if(tar < c[ix]) { v.pop_back(); return ; } 
    hlpr(c,tar-c[ix],ix,v); 
    v.pop_back();
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        n = candidates.size();
        vector<int> v;
    hlpr(candidates,target,0,v);
    return ans;
    }
}; 