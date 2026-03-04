class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(); int  n = mat[0].size();
        vector<int> row(m);
        vector<int> cols(n);
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]==1){ row[i]++; cols[j]++;}
            }
        }
        int count = 0;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(row[i]==1 && cols[j]==1 && mat[i][j]==1) count++;
            }
        }
    return count;
    }
};