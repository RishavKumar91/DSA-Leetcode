class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m  = boxGrid.size();
        int n  = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, 0));
        for(int i = 0;i<m;i++){
            for(int j = 0 ;j<n;j++){
                ans[j][i] = boxGrid[i][j] ;
            }
        }
        for( auto &g : ans) reverse(g.begin(),g.end());

        for(int col = 0 ; col < m; col++){
            int bottomkhali = n-1;
            for(int row = n-1 ; row>=0 ; row--){
                if(ans[row][col] == '*') bottomkhali = row-1;
                else if(ans[row][col] == '#') {
                    swap(ans[bottomkhali][col],ans[row][col]);
                    bottomkhali--;
                }
            }
        }
    return ans;
    }
};