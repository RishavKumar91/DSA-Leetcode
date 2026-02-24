class Solution {
public:
void bfs(vector<vector<char>>& grid,vector<vector<bool>>& visit,int i ,int j){
    queue<pair<int,int>> q;
    int m = grid.size() , n = grid[0].size();
    q.push({i,j});
    visit[i][j]=1;
    while(!q.empty()){
        // visit[i][j]=1;
        pair<int,int> p = q.front();
        int f = p.first;
        int s = p.second;
        q.pop();
        if(s+1 < n && visit[f][s+1]==0 && grid[f][s+1]=='1' ) 
            {q.push({f,s+1}); visit[f][s+1]=1;}
        if(f+1<m &&visit[f+1][s]==0  && grid[f+1][s]=='1') 
            {q.push({f+1,s});visit[f+1][s]=1;}
        if(f-1>=0 && visit[f-1][s]==0  && grid[f-1][s]=='1') 
            {q.push({f-1,s});visit[f-1][s]=1;}
        if(s-1 >=0 && visit[f][s-1]==0  && grid[f][s-1]=='1') 
            {q.push({f,s-1});visit[f][s-1]=1;}
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visit(m, vector<bool>(n,0));
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1' && visit[i][j]==0){
                    bfs(grid,visit,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};