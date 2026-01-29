class Solution {
public:
bool ok(vector<vector<char>> &bor,int row,int col,int n){
    int i,j;
    for(i =0;i<row;i++){    // row chck
        if(bor[i][col]=='Q') return 0;
    }
    i=row-1,j=col+1;
    while(i>=0&&j<n){         // NE
        if(bor[i][j]=='Q') return 0;
    i--;j++;
    }
    i=row-1,j=col-1;
    while(i>=0&&j>=0){        //NW
        if(bor[i][j]=='Q') return 0;
    i--;j--;
    }
    return 1;
}
void helper(int n,vector<vector<char>> &bor,int x,int &ans){
    if(x==n){
        ans++;
        return;
    }
    for(int j =0;j<n;j++){
        if(ok(bor,x,j,n)) {
            bor[x][j] = 'Q';
            helper(n,bor,x+1,ans);
            bor[x][j] = '.';
            }
    }      
}
    int totalNQueens(int n) {
        int ans=0;
        vector<vector<char>> bor(n, vector<char>(n));
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                bor[i][j] = '.';
            }
        }
        helper(n,bor,0,ans);
        return ans;
    }
};