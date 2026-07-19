class Solution {
public:
vector<int> dp;
int hlpr(int n){
    if(n==1 ) return 1;
    if(dp[n] != -1) return dp[n];
    int ans = INT_MIN;
    for(int i = 1 ; i < n ; i++){
        int nowans = max(hlpr(n-i)*i , i * (n-i));
        ans = max(ans,nowans);
    }
return dp[n] = ans;
}
    int integerBreak(int n) {
        dp.resize(n+1,-1);
        return hlpr(n);
    }
};