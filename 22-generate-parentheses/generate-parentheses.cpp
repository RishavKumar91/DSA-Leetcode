class Solution {
public:
vector<string> ans;
void hlpr(int i ,int j , int n ,string s){
    if(i > n) return ;
    if(s.size() == 2*n){
        ans.push_back(s);
        return;
    }
    hlpr(i+1,j,n,s+"(");
    if( j < i ) hlpr(i,j+1,n,s+")");
}
    vector<string> generateParenthesis(int n) {
        hlpr(0,0,n , "");
        return ans;
    }
};