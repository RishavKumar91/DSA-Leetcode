class Solution {
public:
void hlpr(int  n , vector<string> & ans,string s,int i ,int j ){
    if(i>n || j>n) return;
    if(s.size()== 2*n && i==j){
        ans.push_back(s);
        return ;
    }
    hlpr(n,ans,s+"(",i+1,j);
    if(j<i) hlpr(n,ans,s+")",i,j+1);
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        hlpr(n,ans,"(",1,0);
    return ans;
    }
};