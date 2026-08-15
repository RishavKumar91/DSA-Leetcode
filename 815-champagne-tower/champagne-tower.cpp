class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 2,vector<double>(query_row + 2, 0.0));
        dp[0][0] = (double)poured ;
        for(int i = 0 ; i <= query_row ; i++){
            for(int j = 0 ; j <= i ; j++){
                if(dp[i][j] > 1.0){
                double remhalf = (dp[i][j]-1.0)/2.0 ;
                    dp[i][j] = 1.0;
                    dp[i+1][j] += remhalf;
                    dp[i+1][j+1] += remhalf;
                }
            }
        }
    return dp[query_row][query_glass] >= 1.0 ? 1.0 : dp[query_row][query_glass] ;
    }
};