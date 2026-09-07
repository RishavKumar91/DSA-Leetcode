class Solution {
public:
int M = 1e9+7;
int n;
vector<int> prv;
vector<int> dp;
    int hlpr(int i){
        if(i==0) return 1;
        if(dp[i] != -1) return dp[i];
        long long ans = 0 ;
        ans = 2 * hlpr(i-1);
        if(prv[i-1] != -1){
            ans = (ans- hlpr(prv[i-1]) + M) % M;
        }
    return dp[i] =  (ans + M) % M ;
    }
    int distinctSubseqII(string s) {
        n = s.size();
        prv.resize(n+1,-1);
        dp.resize(n+1,-1);
        vector<int> last(26,-1);
        for(int i = 0 ; i < n ; i++){
            int charix = s[i] - 'a';
            prv[i] = last[charix] ; 
            last[charix] = i ; 
        }
    return (hlpr(n)-1+M)%M;
    }
};