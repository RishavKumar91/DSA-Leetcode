class Solution {
public:
typedef long long ll;
ll total  = 0;
bool chck(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    ll now = 0;
    unordered_set<ll> s;
    for(int i = 0;i<m-1;i++){
        for(int j = 0;j<n;j++){
            now+=grid[i][j];
            s.insert(grid[i][j]);
        }
        ll lft = total - now;
        ll diff = now - lft;
        if(diff==0 ) return 1;
        if(diff==grid[0][0]) return 1;
        if(diff == grid[0][n-1]) return 1;
        if(diff== grid[i][0]) return 1;
        if( i>0 && n>1 && s.count(diff)) return 1;
    }
return 0;
}
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0 ;j<n;j++){
                total+=grid[i][j];
            }
        }
        if(chck(grid)) return 1;
        reverse(grid.begin(),grid.end());
        if(chck(grid)) return 1;
        vector<vector<int>> mat(n,vector<int> (m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                mat[i][j] = grid[j][i];
            }
        }
        if(chck(mat)) return 1;
        reverse(mat.begin(),mat.end());
        if(chck(mat)) return 1;
    return 0;
    }
};