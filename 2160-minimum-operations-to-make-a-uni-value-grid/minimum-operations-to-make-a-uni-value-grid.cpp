class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int s = m*n;
        int h = s/2;
        sort(v.begin(),v.begin()+h);
        int tar = v[h];
        int ans = 0;
        for(int i = 0;i<s;i++){
            int diff = abs(v[i] - tar);
            if(diff%x != 0) return -1;
            ans+=diff/x;
        }
    return ans;
    }
};