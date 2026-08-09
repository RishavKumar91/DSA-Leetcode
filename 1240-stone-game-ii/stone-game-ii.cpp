class Solution {
public:
int n , total = 0 ;
vector<vector<int>> dp;
    int hlpr(vector<int>& piles , int currix , int M){
        if(currix >= n) return 0;
        if( dp[currix][M] != -1 ) return dp[currix][M];
        int ans = INT_MIN , sum = 0;
        for(int i = 1 ; (i <= 2*M && currix+i-1 < n) ; i++){
            sum += piles[currix+i-1];
            ans = max(ans , sum - hlpr(piles, currix+i, max(M,i)) );
        }
    return dp[currix][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.assign(n+1,vector<int> (n+1,-1));
        total = accumulate(piles.begin() , piles.end(),0);
        int diff = hlpr(piles, 0, 1);

        return (total + diff) / 2;
    }
};