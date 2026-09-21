class Solution {
public:
    vector<vector<int>> dp;
    int hlpr(int m , int n){
        if(m < 0 || n < 0 ) return 0;
        if( m == 0 && n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n] ;
        return dp[m][n] = hlpr(m-1,n) + hlpr(m,n-1);
    }
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int> (n+1,-1));
        return hlpr(m-1,n-1);
    }
};