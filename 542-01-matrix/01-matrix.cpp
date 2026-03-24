class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(m,vector<int> (n,-1));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j] =0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            if(p.first+1 < m && ans[p.first+1][p.second] == -1) {
                ans[p.first+1][p.second] = ans[p.first][p.second] + 1;
                q.push({p.first+1,p.second});
            }
            if(p.first-1 >= 0  && ans[p.first-1][p.second] == -1) {
                ans[p.first-1][p.second] = ans[p.first][p.second] + 1;
                q.push({p.first-1,p.second});
            }
            if(p.second+1 < n && ans[p.first][p.second+1] == -1) {
                ans[p.first][p.second+1] = ans[p.first][p.second] + 1;
                q.push({p.first,p.second+1});
            }
            if(p.second-1 >=0 && ans[p.first][p.second-1] == -1) {
                ans[p.first][p.second-1] = ans[p.first][p.second] + 1;
                q.push({p.first,p.second-1});
            }
        }
    return ans;
    }
};