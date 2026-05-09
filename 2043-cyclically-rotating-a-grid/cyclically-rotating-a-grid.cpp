class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        int layr = min(m/2,n/2);
        for(int i = 0 ;i<layr;i++){
            int top = i , bottom = m-i;
            int lft = i , right = n-i;

            vector<int> v;
            for(int j = lft; j<right ;j++)      v.push_back(grid[top][j]);
            for(int j = top+1;j<bottom;j++)   v.push_back(grid[j][right-1]);
            for(int j = right-2 ; j>=lft ;j--)  v.push_back(grid[bottom-1][j]);
            for(int j = bottom-2;j>=top+1;j--)  v.push_back(grid[j][lft]);

int sz = v.size();
int nk = k%sz;
// for(int tim = 0 ;tim<nk;tim++){
//     int first = v[0];
//     for(int s = 0 ;s<sz-1;s++) v[s] = v[s+1];
//     v[sz-1] = first;
// }
rotate(v.begin(), v.begin() + nk, v.end());

            int ix = 0;
            for(int j = lft; j<right ;j++)      grid[top][j] = v[ix++];
            for(int j = top+1;j<bottom;j++)   grid[j][right-1]   = v[ix++];
            for(int j = right-2 ; j>=lft ;j--)  grid[bottom-1][j]  = v[ix++];
            for(int j = bottom-2;j>=top+1;j--)  grid[j][lft]  = v[ix++];
        }
        return grid;
    }
};