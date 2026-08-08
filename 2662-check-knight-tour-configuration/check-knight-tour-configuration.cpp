class Solution {
public:
int n ;
    vector<pair<int,int>> dxn = {{1,2},{1,-2},{-1,2},{-1,-2} ,{2,1},{2,-1},{-2,1},{-2,-1}};
    bool dfs(int i , int j , vector<vector<int>>& grid , int count){
        if(count >= n*n) return 1;
        for(auto &p : dxn){
            int ni = p.first + i ;
            int nj = p.second + j;
            if(ni < 0 || nj < 0 || ni>= n || nj >=n ) continue;
            if(grid[ni][nj] == count) {
                if(dfs(ni,nj,grid,count+1)) return 1;
            }
        }
    return 0;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        n = grid.size();
        return dfs(0,0,grid,1);
    }
};