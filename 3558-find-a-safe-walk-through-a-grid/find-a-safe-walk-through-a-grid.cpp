class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<bool>> visit(m,vector<bool> (n,0));
        queue<pair<int,int>> q0;
        queue<pair<int,int>> q1;
        visit[0][0] = 1;
        if(grid[0][0] == 1){ q1.push({0,0}); }
        else q0.push({0,0});

        while(!q0.empty() || !q1.empty()){
            if(!q0.empty()){
                while(!q0.empty()){
                    auto [x,y] = q0.front();
                    if(x==m-1 && y == n-1) return health > 0;
                    q0.pop();
                    if(x+1 <m && visit[x+1][y]==0   ){
                        visit[x+1][y] = 1;
                        if(grid[x+1][y]==0) q0.push({x+1,y});
                        else q1.push({x+1,y});}
                    if(x-1 >= 0 && visit[x-1][y]==0  ){
                        visit[x-1][y] = 1;
                        if(grid[x-1][y]==0) q0.push({x-1,y});
                        else q1.push({x-1,y});}
                    if(y+1 <n && visit[x][y+1]==0  ){
                        visit[x][y+1] = 1;
                        if(grid[x][y+1]==0) q0.push({x,y+1});
                        else q1.push({x,y+1});}
                    if(y-1 >=0  && visit[x][y-1]==0  ){
                        visit[x][y-1] = 1;
                        if(grid[x][y-1]==0) q0.push({x,y-1});
                        else q1.push({x,y-1});}
                }
            }
            else{
                health--;
                int sz = q1.size();
                for(int i = 0 ; i < sz ; i++){
                    auto [x,y] = q1.front();
                    if(x==m-1 && y == n-1) return health > 0;
                    q1.pop();
                    if(x+1 <m && visit[x+1][y]==0   ) {
                        visit[x+1][y] = 1;
                        if(grid[x+1][y]==0) q0.push({x+1,y});
                        else q1.push({x+1,y});}
                    if(x-1 >= 0 && visit[x-1][y]==0  ){
                        visit[x-1][y] = 1;
                        if(grid[x-1][y]==0) q0.push({x-1,y});
                        else q1.push({x-1,y});}
                    if(y+1 <n && visit[x][y+1]==0  ){
                        visit[x][y+1] = 1;
                        if(grid[x][y+1]==0) q0.push({x,y+1});
                        else q1.push({x,y+1});}
                    if(y-1 >=0  && visit[x][y-1]==0  ){
                        visit[x][y-1] = 1;
                        if(grid[x][y-1]==0) q0.push({x,y-1});
                        else q1.push({x,y-1});}
                }
            }
        }
    return 0;
    }
};