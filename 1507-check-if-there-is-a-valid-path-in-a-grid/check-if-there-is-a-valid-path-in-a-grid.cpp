class Solution {
public:
int m , n ;
unordered_map<int, vector<vector<int>>> mp = {
        {1, {{0,-1}, {0,1}}},
        {2, {{-1,0}, {1,0}}},
        {3, {{0,-1}, {1,0}}},
        {4, {{0,1}, {1,0}}},
        {5, {{-1,0}, {0,-1}}},
        {6, {{-1,0}, {0,1}}}
    };
bool fs(int i , int j , vector<vector<int>>& grid,vector<vector<bool>> &visit){
    if(i==m-1 && j==n-1) return 1;
    visit[i][j] = 1;
    for(auto dxn : mp[grid[i][j]]){
        int ni = i + dxn[0];
        int nj = j + dxn[1];
        if(ni<0 || nj<0 || ni>=m || nj>=n || visit[ni][nj]) continue;
        for(auto &back : mp[grid[ni][nj]]){
            if(ni+back[0]==i && nj+back[1]==j)
                if(fs(ni,nj,grid,visit)) return 1;
        }
    }
return 0;
}
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, 0));
        return fs(0,0,grid,visit);
    }
};