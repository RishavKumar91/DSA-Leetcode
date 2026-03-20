class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1, 0));
        for(int i = 0;i<m-k+1;i++){
            for(int j = 0;j<n-k+1;j++){

                vector<int> v;
                for(int a = i;a<i+k;a++){
                    for(int b = j;b<j+k;b++){
                        v.push_back(grid[a][b]);
                    }
                }

            // if(v.size()==1) ans[i][j] = 0;
            
                sort(v.begin(),v.end());
                int minn = INT_MAX;
                    for(int z = 1;z<v.size();z++){
                        if(v[z]!=v[z-1]) minn = min(minn,v[z]-v[z-1]);
                    }
                ans[i][j] = minn==INT_MAX ? 0: minn;
            

    }
        }
    return ans;
    }
};