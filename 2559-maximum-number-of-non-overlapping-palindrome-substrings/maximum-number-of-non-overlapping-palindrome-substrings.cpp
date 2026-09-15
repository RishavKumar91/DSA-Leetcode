class Solution {
public:
int n ;
vector<vector<int>> dp;
vector<vector<bool>> dpal;
    int hlpr(string &s , int k , int i , int j){
        if(i >= n) return 0;
        if(j >= n) return  hlpr(s,k,i+1,i+k-1);
        if(dp[i][j] != -1) return dp[i][j] ; 
        if( !dpal[i][j] || j-i+1 < k ) return dp[i][j] =  hlpr(s,k,i,j+1) ;
        if(dpal[i][j] ) return dp[i][j] = max( 1 + hlpr(s,k,j+1,j+k) , hlpr(s,k,i,j+1) ) ;
        return dp[i][j] =  hlpr(s,k,i,j+1) ;
    }
    int maxPalindromes(string s, int k) {
        n = s.size();
        if(k == 1) return n ;
        dp.resize(n+1,vector<int> (n+1,-1));
        dpal.resize(n+1,vector<bool> (n+1,-1));
        for(int i = n - 1; i >= 0; i--) {
            dpal[i][i] = 1;

            for(int j = i + 1; j < n; j++) {
                dpal[i][j] = (s[i] == s[j]) &&
                             (j - i == 1 || dpal[i + 1][j - 1]);
            }
        }
        return hlpr(s,k,0,k-1);
    }
};