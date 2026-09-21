class Solution {
public:
int m , n ;
vector<vector<int>> dp;
    int hlpr(int i , int j, vector<vector<int>>& obs){
        if(i < 0 || j < 0 || obs[i][j] == 1 ) return 0;
        if( i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j] ;
        return dp[i][j] = hlpr(i-1,j,obs) + hlpr(i,j-1,obs);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        m = obs.size();
        n = obs[0].size();
        dp.resize(m+1,vector<int> (n+1,-1));
        return hlpr(m-1,n-1,obs);
    }
};