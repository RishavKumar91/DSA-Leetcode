class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int,int>>> v(m, vector<pair<int,int>>(n));
        int ans = 0;
        for(int i = 0 ;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='X') v[i][j].first++;
                if(grid[i][j]=='Y') v[i][j].second++;
                if(i-1>=0){ 
                    v[i][j].first +=v[i-1][j].first;
                    v[i][j].second +=v[i-1][j].second;
                }
                if(j-1>=0){ 
                    v[i][j].second +=v[i][j-1].second;
                    v[i][j].first +=v[i][j-1].first;
                }
                if(i-1>=0 && j-1>=0){
                    v[i][j].first -=v[i-1][j-1].first;
                    v[i][j].second -=v[i-1][j-1].second;

                }
                if(v[i][j].first == v[i][j].second && v[i][j].first>0) ans++;
            }
        }
    return ans;
    }
};