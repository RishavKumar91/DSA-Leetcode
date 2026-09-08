class Solution {
public:
int n;
vector<vector<int>> dp ;
    bool chck(int i , int j , string &s){
        int ii = i , jj = j ;
        if(dp[i][j] != -1) return dp[ii][jj] ;
        while(i<j ){
            if(s[i] != s[j]) return dp[ii][jj] = 0;
            i++;
            j--;
        }
    return dp[ii][jj] = 1;
    }
    int countSubstrings(string s) {
        n = s.size();
        dp.resize(n+1,vector<int> (n+1,-1));
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(chck(i,j,s)) ans++;
            }
        }
    return ans;
    }
};