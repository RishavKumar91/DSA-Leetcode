class Solution {
public:
bool saf(int row , int col , vector<vector<char>>& board , char ch ){
    for(int i = 0 ; i < 9 ; i++){
        if(board[row][i] == ch || board[i][col] == ch) return 0;
    }
    row = (row/3)*3 , col = (col/3)*3 ;
    for(int i = row ; i < row + 3 ; i++){
        for(int j = col ; j < col + 3 ; j++){
            if(board[i][j] == ch) return 0;
        }
    }
    return 1;
}
bool backtrack(vector<vector<char>>& board){
    for(int i = 0  ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){

            if(board[i][j] == '.'){
                for(char ch = '1' ; ch <= '9' ; ch++){
                    if(saf(i,j,board,ch)){
                        board[i][j] = ch;
                        if(backtrack(board)) return 1;
                        board[i][j] = '.';
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};