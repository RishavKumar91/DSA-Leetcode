class Solution {
public:
int n;
vector<vector<int>> dp ;
    bool chck(int i, int j, string &s){
    if(i >= j) return true;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s[i] != s[j])
        return dp[i][j] = 0;

    return dp[i][j] = chck(i + 1, j - 1, s);
}
    int countSubstrings(string s) {
        n = s.size();
        dp.assign(n+1,vector<int> (n+1,-1));
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(chck(i,j,s)) ans++;
            }
        }
    return ans;
    }
};