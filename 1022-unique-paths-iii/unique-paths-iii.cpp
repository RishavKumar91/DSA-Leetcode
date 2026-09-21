class Solution {
public:
int starti , startj , lasti , lastj , m , n ,count , ans ;
vector<pair<int,int>> dxn = {{0,1},{1,0},{-1,0},{0,-1}} ;
    void hlpr(vector<vector<int>>& obs , int i , int j){
        if( i == lasti && j == lastj){
            if(count == -1) ans++;
        return ;
        }
        for(auto &x : dxn){
            int ni = i + x.first;
            int nj = j + x.second;
            if(ni < 0 || nj < 0 || ni >= m || nj >= n || obs[ni][nj] == -1) continue ; 
            obs[ni][nj] = -1;
            count--;
            hlpr(obs,ni,nj) ;
            obs[ni][nj] = 0 ;
            count++;
        }
    }
    int uniquePathsIII(vector<vector<int>>& obs) {
        m = obs.size() , n = obs[0].size() , count = 0;
        ans = 0 ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(obs[i][j] == 1){
                    starti = i ;
                    startj = j ;
                }
                else if(obs[i][j] == 2){
                    lasti = i ;
                    lastj = j ;
                }
                else if(obs[i][j] == 0){
                    count++ ;
                }
            }
        }
        obs[starti][startj] = -1;
        hlpr(obs,starti,startj);
    return ans;
    }
};