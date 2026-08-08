class Solution {
public:
vector<vector<string>> ans;
bool chck(int row , int col , vector<string> &bor){
    int n  = bor.size();
    for(int i = 0 ; i < row ; i++){
        if(bor[i][col] == 'Q') return 0;
    }
    for(int i = 0 ; i < col ; i++){
        if(bor[row][i] == 'Q') return 0;
    }
    int i = row-1 , j = col-1;
    while(i >= 0 && j >= 0){
        if(bor[i][j] == 'Q') return 0;
        i--; j--;
    }
    i = row-1 , j = col+1;
    while(i >= 0  && j < n){
        if(bor[i][j] == 'Q') return 0;
        i--; j++;
    }
    return 1;
}
void backtrack(vector<string> bor , int row ){
    int n = bor.size();
    if(n==row){
        ans.push_back(bor);
        return ;
    }
    for(int i = 0 ; i < n ; i++){
        if(chck(row,i,bor)){
            bor[row][i] = 'Q';
            backtrack(bor,row+1);
            bor[row][i] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> bor(n,string(n,'.'));
        backtrack(bor,0);
        return ans;
    }
};