class Solution {
public:
    int fxnn(int start , int last , string &s,vector<vector<int>> &dp){
        if(start == last) return 1;
        if(start>last) return 0;
        if(dp[start][last] != -1) return dp[start][last];
        if(s[start] == s[last]) return 2 + fxnn(start+1,last-1,s,dp);
        int f1 = fxnn(start+1,last,s,dp);
        int f2 = fxnn(start,last-1,s,dp);
        return dp[start][last] = max(f1,f2);
    }
    int longestPalindromeSubseq(string s) {
        // int start = 0;
        int n = s.size();
        int last = s.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return fxnn(0,n-1,s,dp);
    }
};