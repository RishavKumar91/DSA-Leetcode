// class Solution {
// public:
//     int hlpr(vector<int> & cost,vector<int> &dp,int ix){
//         if(ix<=1) return cost[ix]; 
//         if(dp[ix]!=0) return dp[ix];
//         return dp[ix] = cost[ix] + min(hlpr(cost,dp,ix-1),hlpr(cost,dp,ix-2));
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n);
//         return min(hlpr(cost,dp,n-1),hlpr(cost,dp,n-2));
//     }
// };

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];     dp[1] = cost[1];
        for(int i =2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-2],dp[n-1]);
    }
};