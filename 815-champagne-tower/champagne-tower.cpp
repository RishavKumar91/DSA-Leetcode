class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100, vector<double>(100, 0));
        double p = poured;
        dp[0][0] = p;
        for(int i =0;i<query_row;i++){
            for(int j = 0;j<=i;j++){
                if(dp[i][j]>1.0){
                    double remhalf = (dp[i][j] - 1.0)/2;
                    dp[i][j] = 1.0;
                    dp[i+1][j] += remhalf;
                    dp[i+1][j+1] +=remhalf;
                }
            }
        }
    return min(dp[query_row][query_glass],1.0);
    }
};