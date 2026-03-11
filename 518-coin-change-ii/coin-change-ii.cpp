class Solution {
public:
int fxn(vector<int> &coins,int left,int ix,vector<vector<int>> &dp){
    if(left==0) { return 1;}
    if(ix == coins.size()) return 0;
    if(dp[ix][left] != -1)  return dp[ix][left]; 
    int take = 0;
    if(coins[ix]<=left) take =  fxn(coins,left - coins[ix],ix,dp);
    int skip = fxn(coins,left,ix+1,dp);
    return dp[ix][left] = take + skip;

}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(301, vector<int>(5001, -1));
        int ans = fxn(coins,amount,0,dp);
        return ans ; 
    }
};