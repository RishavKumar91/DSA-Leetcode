class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> ans(m, vector<long long>(n,0));

        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0 && j==0) ans[i][j] = grid[i][j]; 
                else if(i==0)  ans[i][j] = grid[i][j] + ans[i][j-1];
                else if(j==0)  ans[i][j] = grid[i][j] + ans[i-1][j];
                else 
                    ans[i][j] = min(grid[i][j] + ans[i-1][j], grid[i][j] + ans[i][j-1]); 
            }
        }
    return ans[m-1][n-1];
    }
};