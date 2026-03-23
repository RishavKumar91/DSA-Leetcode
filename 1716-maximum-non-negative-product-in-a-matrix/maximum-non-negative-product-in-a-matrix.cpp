class Solution {
public:
const int MOD = 1e9+7;
    pair<long long,long long> solv(int i,int j,vector<vector<int>>& grid,
    vector<vector<pair<long long ,long long>>> &dp ){
        int m = grid.size();    int n = grid[0].size();
        if(dp[i][j].first != LLONG_MAX) return dp[i][j];
        if(i==m-1 && j ==n-1) return {grid[i][j],grid[i][j]};
        long long maxnow = LLONG_MIN, minnow = LLONG_MAX;
        if(i<m-1){
            auto [downmax,downmin] = solv(i+1,j,grid,dp);
            maxnow = max(maxnow,max(grid[i][j]*downmax,grid[i][j] *downmin));
            minnow = min({minnow,grid[i][j]*downmax,grid[i][j] *downmin});
        }
        if(j<n-1){
            auto [rightmax,rightmin] = solv(i,j+1,grid,dp);
            maxnow = max({maxnow,grid[i][j]*rightmax,grid[i][j] *rightmin});
            minnow = min({minnow,grid[i][j]*rightmax,grid[i][j] *rightmin});
        }
        return dp[i][j] = {maxnow,minnow};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
vector<vector<pair<long long,long long>>> dp(m,vector<pair<long long,long long>>(n,{LLONG_MAX,LLONG_MIN}));
        auto [ansmax,ansmin] = solv(0,0,grid,dp);
        return ansmax >= 0 ? ansmax%MOD : -1 ;
    }
};