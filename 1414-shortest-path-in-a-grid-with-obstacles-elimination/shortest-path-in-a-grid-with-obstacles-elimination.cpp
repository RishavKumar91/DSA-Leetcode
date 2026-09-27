class Solution {
public:
    vector<pair<int,int>> dxn = {{0,1},{1,0},{-1,0},{0,-1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        // vector<vector<vector<bool>>> visit(m,vector<vector<bool>> (n,vector<bool> (k+1,0)));
        bool visit[m+1][n+1][k+1];
        memset(visit,0,sizeof(visit));
        queue<vector<int>> q;
        q.push({0,0,k});
        visit[0][0][k] = 1 ;
        int ans = 0 ;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto tmp = q.front();
                int r = tmp[0] , c = tmp[1] , rm = tmp[2];
                if(r == m-1 && c == n-1) return ans ; 
                q.pop();
                for(auto d : dxn){
                    int nr = r + d.first , nc = c + d.second ;
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n ) continue ;
                    int nrm = rm - grid[nr][nc];
                    if( nrm < 0 || visit[nr][nc][nrm]) continue;
                    q.push({nr,nc,nrm});
                    visit[nr][nc][nrm] = 1;
                }
            }
        ans++;
        }
    return -1;
    }
};