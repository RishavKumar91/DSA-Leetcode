class Solution {
public:
int solv(string & T1,string & T2 , int i,int j,vector<vector<int>> &matrix){
    if(i==T1.size() || j==T2.size() ) 
        return 0;
    if(matrix[i][j]!=-1) 
        return matrix[i][j];
    if(T1[i] == T2[j]) 
        return matrix[i][j] = 1 + solv(T1,T2,i+1,j+1,matrix);
    int skipT1 = solv(T1,T2,i+1,j,matrix);
    int skipT2 = solv(T1,T2,i,j+1,matrix);
    return matrix[i][j] = max(skipT1,skipT2);
}
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> matrix(text1.size(), vector<int>(text2.size(), -1));
        return solv(text1,text2,0,0,matrix);
    }
};