class Solution {
public:
int M = 1e9 + 7 ;
vector<vector<int>> moves ={
    {4,6},
    {6,8},
    {7,9},
    {4,8},
    {3,9,0},
    {},
    {1,7,0},
    {2,6},
    {1,3},
    {2,4}
} ;
vector<vector<int>> dp;
    int hlpr(int now , int n ){
        if(n == 0 ) return 1 ;
        int ans = 0 ;
        if(dp[now][n] != -1) return dp[now][n];
        for(int i = 0 ;  i < moves[now].size(); i++){
            ans = ( 0LL + ans +  hlpr( moves[now][i]  , n-1)) % M ;
        }
        return dp[now][n] =  ans;
    }
    int knightDialer(int n) {
        int ans = 0 ;
        dp.resize(10,vector<int> (n+1,-1));
        for(int i = 0 ; i <= 9 ; i++){
            ans = ( 0LL + ans + hlpr(i,n-1) ) % M ;
        }
    return ans ; 
    }
};