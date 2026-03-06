class Solution {
public:
int fxn(vector<int> &coins,int left,int ix,vector<vector<int>> &dp){
    if(left==0) return 0;
    if(ix == coins.size()) return 1e9;
    if(dp[ix][left] != -1) return dp[ix][left]; 
    int n = left/coins[ix];
    int take = 1e9;
    if(coins[ix]<=left) take = 1 + fxn(coins,left - coins[ix],ix,dp);
    int skip = fxn(coins,left,ix+1,dp);
    return dp[ix][left] = min(skip,take);

}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(13, vector<int>(10001, -1));
        int ans = fxn(coins,amount,0,dp);
        
        return ans >=1e9 ? -1 : ans ; 
    }
};