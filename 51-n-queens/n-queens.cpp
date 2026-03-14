class Solution {
public:
bool chck(int row,int col , vector<string> &bor,int &n){
    int i = row-1 , j = col-1;
    while(i>=0){
        if(bor[i][col]=='Q' ) return 0;
        i--;
    }
    i= row-1;
    j = col-1;
    while(i>=0 && j>=0){
        if(bor[i][j]=='Q') return 0;
    j--;
    i--;
    }
    i = row-1;
    j = col+1;
    while(i>=0 && j<n){
        if(bor[i][j]=='Q') return 0;
        i--;
        j++;
    }
return 1;
}
void hlpr(int row ,vector<string> &bor, vector<vector<string>> &ans,int &n){
    if(row==n){
        ans.push_back(bor);
        return;
    }
    for(int i = 0;i<n;i++){
        if(chck(row,i,bor,n)){
            bor[row][i]= 'Q';
            hlpr(row+1,bor,ans,n);
            bor[row][i] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> bor(n, string(n,'.'));
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                bor[i][j] = '.';
            }
        }
        hlpr(0,bor,ans,n);
        return ans;
    }
};