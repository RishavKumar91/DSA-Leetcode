class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        bool up = 1;
        int i = 0 ,j =0;
        while(ans.size()!=m*n){
            if(up){
                while(i>=0 && j<n){
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }
                if(i==-1 && j==n) {i+=2; j--;} 
                else if(i==-1) {i++ ; }
                else {j--; i+=2;}
            }
            else {
                while(i<m && j>=0){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
                if(i==m && j==-1) {i-- ; j+=2;}
                else if(j==-1) { j++;}
                else {j+=2; i--;}
            }
            up = !up;
        }
    return ans;
    }
};