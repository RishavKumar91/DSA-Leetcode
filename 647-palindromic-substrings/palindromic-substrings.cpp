class Solution {
public:
int n;
vector<vector<int>> dp ;
    int hlpr(int i , int j , string &s){
        if(dp[i][j] != -1) return dp[i][j];
        int count = 0 ;
        int ii = i , jj = j;
        while(i >= 0 && j < n && s[i]==s[j]){
            i--;
            j++;
            count++;
        }
        return dp[ii][jj] = count;
    }
    int countSubstrings(string s) {
        n = s.size();
        dp.resize(n+1,vector<int> (n+1,-1)) ; 
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            ans += hlpr(i,i,s);
            ans += hlpr(i,i+1,s);
        }
    return ans;
    }
};