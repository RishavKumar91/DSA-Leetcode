class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, 0));
        vector<pair<int ,int> > dxn = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(visit[i][j]==0){
                    queue<tuple<int,int,int,int>> q;
                    q.push({i,j,-1,-1});
                    while(!q.empty()){
                        auto [x,y,px,py] = q.front();
                        visit[x][y] = 1;
                        q.pop();
                        for(auto d : dxn){
                            int nx = x+d.first , ny = y+d.second;
                            if(nx<m && nx>=0 && ny<n && ny>=0 && grid[nx][ny]==grid[x][y]){
                                if(visit[nx][ny]==0 ){
                                    q.push({nx,ny,x,y});
                                }
                                else if(nx!=px || ny!=py) return 1;
                            }
                        }
                    }
                }
            }
        }
    return 0;
    }
};