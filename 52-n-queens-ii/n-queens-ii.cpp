class Solution {
public:
bool ok(int row,int col,vector<string> & bor){
    int i = row;
    int j = col;
    while(i>=0){
        if(bor[i][j]=='Q') return 0;
        i--;
    }
    i = row-1; j = col-1;
    while(i>=0 && j>=0){
        if(bor[i][j]=='Q') return 0;
        i--; j--;
    }
    i = row-1;
    j = col+1;
    while(i>=0 && j<bor.size()){
        if(bor[i][j]=='Q') return 0;
        i--; j++;
    }
return 1;
}
void solve(int &ans,int &n,vector<string> &bor,int row){
    if(row==n){
        ans++;
        return ;
    }
    for(int i = 0;i<n;i++){
        if(ok(row,i,bor)){
            bor[row][i] = 'Q';
            solve(ans,n,bor,row+1);
            bor[row][i] = '.';
        }
    }
}
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> bor(n, string(n,'.'));
        solve(ans,n,bor,0);
    return ans;
    }
};