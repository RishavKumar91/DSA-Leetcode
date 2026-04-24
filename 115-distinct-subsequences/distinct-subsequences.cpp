class Solution {
public:
int m , n;
int solv(string &s,string &t,int i,int j,vector<vector<int>> &matrix){
    if(j==n) return 1;
    if(i==m) return 0;
    if(matrix[i][j]!=-1) return matrix[i][j];
    if(s[i]==t[j]) return matrix[i][j] = solv(s,t,i+1,j+1,matrix) + solv(s,t,i+1,j,matrix) ;
    return matrix[i][j] = solv(s,t,i+1,j,matrix) ;
}
    int numDistinct(string s, string t) {
        m = s.size() , n = t.size();
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        return solv(s,t,0,0,matrix);
    }
};