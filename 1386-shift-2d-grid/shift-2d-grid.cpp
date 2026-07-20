class Solution {
public:
int m , n ;
void hlpr(vector<vector<int>>& grid){
    int last = grid[m-1][n-1];
        for(int i  = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int prv  = grid[i][j];
                grid[i][j] = last ;
                last = prv;
            }
        }
}
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        m = grid.size() , n = grid[0].size();
        for(int i = 0 ; i < k ; i++) hlpr(grid);
    return grid;
    }
};