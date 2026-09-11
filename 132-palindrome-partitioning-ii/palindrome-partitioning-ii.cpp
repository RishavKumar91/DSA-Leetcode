class Solution {
public:
    int n;
    vector<int> dp ; 
    vector<vector<int>> palindp ;
    bool ispalindrome(int i , int j , string &s){
        if(palindp[i][j] != -1) return palindp[i][j];
        if(i >=j ) return 1;
        if(s[i] != s[j]) return 0;
    return palindp[i][j] =  ispalindrome(i+1,j-1,s);
    }
    int hlpr(int i , string &s){
        if(i==n) return -1;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX ; 
        for(int j = i ; j < n ; j++){
            if(ispalindrome(i,j,s)){
                ans = min(ans,1+hlpr(j+1,s));
            }
        }
    return dp[i] =  ans;
    }
    int minCut(string s) {
        n = s.size();
        palindp.resize(n+1,vector<int> (n+1,-1));
        dp.resize(n+1,-1);
        return hlpr(0,s);
    }
};