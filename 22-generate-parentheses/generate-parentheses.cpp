class Solution {
public:
vector<string> ans;
void hlpr(int i ,int j , int n ,string &s){
    if(i > n) return ;
    if(s.size() == 2*n){
        ans.push_back(s);
        return;
    }
    if(i<n){
        s.push_back('(');
        hlpr(i+1,j,n,s);
        s.pop_back();
    }
    if( j < i ) {
        s.push_back(')');
        hlpr(i,j+1,n,s);
        s.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        string s = "";
        hlpr(0,0,n , s);
        return ans;
    }
};