class Solution {
public:
bool chck(vector<vector<char>>& board , int row , int col){
    int arr[9] = {0};
    for(int i = 0 ;  i < 9 ; i++){
        char ch = board[i][col];
        if(ch != '.'){
            if(arr[ch-'1'] == 1) return 0;
            arr[ch-'1']++;
        }
    }
    memset(arr,0,sizeof(arr));
    for(int i = 0 ;  i < 9 ; i++){
        char ch = board[row][i];
        if(ch != '.'){
            if(arr[ch-'1'] == 1) return 0;
            arr[ch-'1']++;
        }
    }
    memset(arr,0,sizeof(arr));
    row = (row/3)*3 , col = (col/3)*3 ;
    for(int i = row ; i < row+3 ; i++){
        for(int j = col ; j < col + 3 ; j++){
            char ch = board[i][j];
            if(ch != '.'){
                if(arr[ch-'1'] == 1) return 0;
                arr[ch-'1']++;
            }
        }
    }

return 1;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.') continue;
                if(!chck(board,i,j)) return 0;
            }
        }
    return 1;
    }
};