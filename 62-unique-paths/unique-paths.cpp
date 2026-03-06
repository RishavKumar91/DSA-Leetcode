class Solution {
public:
    int hlpr(int i ,int j,int m,int n , vector<vector<int>> &dp ){
        if(i==m-1 || j==n-1) return 1;
        if(dp[i][j] !=-1) return dp[i][j];
        return dp[i][j] = hlpr(i+1,j,m,n,dp) +hlpr(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return hlpr(0,0,m,n,dp);

    }
};