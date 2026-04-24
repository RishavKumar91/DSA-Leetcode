class Solution {
public:
int m , n;
bool backtrack(int i,int j,vector<vector<char>> &board,string &word,int ix){
    if(board[i][j]=='\0' || board[i][j] != word[ix]) return 0;
    if(ix==word.size()-1) return 1;
    char tmp = board[i][j];
    board[i][j] = '\0';
    if( (i+1<m && backtrack(i+1,j,board,word,ix+1) )||
        (j+1<n && backtrack(i,j+1,board,word,ix+1) )||
        (j-1>=0 && backtrack(i,j-1,board,word,ix+1) )||
        (i-1>=0 && backtrack(i-1,j,board,word,ix+1))   )   return 1;
    board[i][j] = tmp;
return 0;
}
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
               if(word[0] ==board[i][j] && backtrack(i,j,board,word,0)) return 1;
            }
        }
    return 0;
    }
};