class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int lastrow = x + k-1;
        int lastcol = y + k-1;
        for(int startrow = x ; startrow<lastrow;startrow++){
            for(int startcol = y; startcol<=lastcol;startcol++){
                swap(grid[startrow][startcol] , grid[lastrow][startcol]);
            }
        lastrow--;
        }
    return grid;
    }
};