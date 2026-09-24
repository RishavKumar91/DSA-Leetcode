class Solution {
public:
vector<int> dp ;
    int hlpr(int n){
        if(n==1) return 0;
        if(dp[n] != -1) return dp[n];
        int ans  = INT_MAX ;
        // for(int i = 1 ; i < n; i++){
        //     ans = min(ans,hlpr(i)  + hlpr(n-1) + i*n-i);
        // }
    return dp[n] = hlpr(1)  + hlpr(n-1) + n-1 ;
    }
    int minCost(int n) {
        dp.resize(n+1,-1);
        return hlpr(n);
    }
};