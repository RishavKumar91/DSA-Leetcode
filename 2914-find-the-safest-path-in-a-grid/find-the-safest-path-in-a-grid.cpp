class Solution {
public:
int m , n ;
    bool ok(int mid , vector<vector<int>>& safe ){
        queue<pair<int,int>> q;
        vector<vector<bool>> visit(m,vector<bool> (n,0));

        q.push({0,0});
        visit[0][0] = 1;
        if (safe[0][0] < mid) return false;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(x==m-1 && y == n-1) return 1; 

            if(x+1 < m && visit[x+1][y]==0 && safe[x+1][y] >= mid) {q.push({x+1,y}); visit[x+1][y] = 1;}
            if(y+1 < n && visit[x][y+1]==0 && safe[x][y+1] >= mid) {q.push({x,y+1}); visit[x][y+1] = 1;}
            if(x-1 >=0 && visit[x-1][y]==0 && safe[x-1][y] >= mid) {q.push({x-1,y}); visit[x-1][y] = 1;}
            if(y-1 >=0 && visit[x][y-1]==0 && safe[x][y-1] >= mid) {q.push({x,y-1}); visit[x][y-1] = 1;}
        }
    return 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> safe(m,vector<int> (n,-1));
        queue<pair<int,int>> q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1) {q.push({i,j}); safe[i][j] = 0 ;}
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if( x+1 < m && safe[x+1][y] == -1 ) {safe[x+1][y] = safe[x][y] +1 ; q.push({x+1,y}); }
            if( x-1 >= 0  && safe[x-1][y] == -1 ) {safe[x-1][y] = safe[x][y] +1 ; q.push({x-1,y}); }
            if( y+1 < n && safe[x][y+1] == -1 ) {safe[x][y+1] = safe[x][y] +1 ; q.push({x,y+1}); }
            if( y-1 >= 0 && safe[x][y-1] == -1 ) {safe[x][y-1] = safe[x][y] +1 ; q.push({x,y-1}); }
        }
        int ans = 0 ;
        int l = 0 , r = 400;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(ok(mid,safe)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
    return ans;
    }
};