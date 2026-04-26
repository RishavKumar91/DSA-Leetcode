class Solution {
public:
    int m, n;
    vector<vector<int>> vis;

    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid){
        // vis[x][y] = 1;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(grid[nx][ny] != grid[x][y]) continue;
           
            if(!vis[nx][ny]){
                vis[nx][ny]=1;
                if(dfs(nx, ny, x, y, grid)){
                    return true;
                }
            }
            else if(nx != px || ny != py){
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vis.assign(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j]){
                    vis[i][j]=1;
                    if(dfs(i, j, -1, -1, grid))

                        return true;
                }
            }
        }

        return false;
    }
};