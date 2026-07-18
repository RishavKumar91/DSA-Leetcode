class Solution {
public:
vector<int> dp;
    int hlpr(int n){
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int i = 1 ; i *i <= n ; i++){
            int nowans = 1 +  hlpr(n-i*i);
            ans = min(ans,nowans);
        }
    return dp[n] = ans;
    }
    int numSquares(int n) {
        dp.resize(n+1,-1);
        return hlpr(n);
    }
};