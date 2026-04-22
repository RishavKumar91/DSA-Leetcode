class Solution {
public:
    bool chck(int i,int j ,string &s,vector<vector<int>> &dp ){
        if(i>=j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = chck(i+1,j-1,s,dp);
        return dp[i][j] =  0;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int ix = -1;
        int maxln  = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i =0;i<n;i++){
            for(int j = i ;j<n;j++){
                if(chck(i,j,s,dp) && maxln<j-i+1){
                    maxln = j-i+1;
                    ix = i;
                }
            }
        }
    return s.substr(ix,maxln);
    }
};