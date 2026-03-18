class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                grid[i][j] = grid[i][j];
                if(i-1 >=0) grid[i][j] += grid[i-1][j];
                if(j-1 >=0) grid[i][j] += grid[i][j-1];
                if(i-1>=0 && j-1>=0) grid[i][j] -= grid[i-1][j-1];
                if(grid[i][j] <=k) ans++;
            }
        }
    return ans;
    }
};