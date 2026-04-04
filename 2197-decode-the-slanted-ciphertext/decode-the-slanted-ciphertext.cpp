class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int  l = encodedText.size();
        int colum = l/rows;

        vector<vector<char>> mat(rows,vector<char> (colum,' '));
        int k = 0;
        for(int i = 0;i<rows;i++){
            for(int j = 0 ;j<colum ;j++){
                mat[i][j] = encodedText[k++];
            }
        }

        string ans = "";
        for(int i = 0;i<colum;i++){
            int j = i ;  k  = 0;
            while(k<rows && j<colum){
                ans+=mat[k][j];
                k++;j++;
            }
        }
    while(ans.size() > 0 && ans[ans.size()-1]==' ') ans.pop_back() ;
    return ans;
    }
};