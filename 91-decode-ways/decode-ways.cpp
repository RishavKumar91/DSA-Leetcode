class Solution {
public:
int n ;
vector<int> dp;
    int hlpr(int ix , string &s){
        if(ix >= n ) return 1;
        if(dp[ix] != -1) return dp[ix];
        int currans  = 0 ;
        if(s[ix] == '0') return 0;
        currans += hlpr(ix+1,s);
        string tmp = s.substr(ix,2);
        if(ix + 1 < n && tmp >= "10" && tmp <= "26") currans += hlpr(ix+2,s);
    return dp[ix] = currans; 
    }
    int numDecodings(string s) {
        n = s.size();
        dp.assign(n+1,-1);
    return hlpr(0,s);
    }
};