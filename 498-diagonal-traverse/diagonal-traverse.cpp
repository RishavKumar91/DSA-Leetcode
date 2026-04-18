class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        vector<vector<int>> v(2*max(n,m) + 1);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                v[i+j].push_back(mat[i][j]);
            }
        }
        for(int i = 0 ;i<2*max(n,m)+1;i++){
            if(i%2!=0)
                for(int j = 0 ;j<v[i].size();j++){
                    ans.push_back(v[i][j]);
                }
            else
                for(int j = v[i].size()-1;j>=0;j--){
                    ans.push_back(v[i][j]);
                }
        }
    return ans;
    }
};