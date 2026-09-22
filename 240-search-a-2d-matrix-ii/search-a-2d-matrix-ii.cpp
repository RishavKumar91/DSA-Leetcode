class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int tar) {
        int m = matrix.size() , n = matrix[0].size();
        int i = 0 , j = n-1 ;
        while( i < m && j >= 0 ){
            if(matrix[i][j] == tar) return 1;
            else if(tar > matrix[i][j]) i++;
            else j--;
        }
    return 0;
    }
};