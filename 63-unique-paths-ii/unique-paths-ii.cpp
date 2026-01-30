class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        if(obstacleGrid[0][0]==1) return 0;
        ans[0][0] =1;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(obstacleGrid[i][j]==1) ans[i][j]=0;
                else {
                    if(i>0) ans[i][j] += ans[i-1][j] ;
                    if(j>0) ans[i][j] +=ans[i][j-1];
                }
            }
        }
    return ans[m-1][n-1];
    }
};