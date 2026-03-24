class Solution {
public:
const int M = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int suff = 1;
        vector<vector<int>> suffix(m, vector<int>(n, 0));
        for(int i  = m-1 ;i>=0;i--){
            for(int j = n-1 ;j >=0 ; j--){
                suffix[i][j] = suff;
                suff  =  ((suff%M) * (grid[i][j]%M))%M;
            }
        }
        int pre = 1;
        for(int i = 0;i<m;i++){
            for(int j = 0 ;j<n;j++){
                suffix[i][j] = (suffix[i][j] * pre)%M;
                pre = ((pre%M) * (grid[i][j]%M))%M;
            }
        }
    return suffix;
    }
};