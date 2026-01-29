class Solution {
public:
bool ok(vector<vector<char>> &bor,int row,int col,int n){
    // for(int j =0;j<col;j++){    // row chck
    //     if(bor[row][j]=='Q') return 0;
    // }
    for(int i =0;i<row;i++){    // col chck
        if(bor[i][col]=='Q') return 0;
    }
    int i =row,j=col;
    // while(i<n&&j<n){           // SE
    //     if(bor[i][j]=='Q') return 0;
    // i++;j++;
    // }
    i=row,j=col;
    // while(i<n&&j>=0){          // SW
    //     if(bor[i][j]=='Q') return 0;
    // i++;j--;
    // }
    i=row,j=col;
    while(i>=0&&j<n){         // NE
        if(bor[i][j]=='Q') return 0;
    i--;j++;
    }
    i=row,j=col;
    while(i>=0&&j>=0){        //NW
        if(bor[i][j]=='Q') return 0;
    i--;j--;
    }
    return 1;
}
void helper(vector<vector<string>> &ans,int n,vector<vector<char>> &bor,int x){
    if(x==n){
        vector<string> tmp;
        for(int i=0;i<n;i++){
            string s="";
            for(int j =0;j<n;j++){
                s.push_back(bor[i][j]);
            }
        tmp.push_back(s);
        }
        ans.push_back(tmp);
        return;
    }
    for(int j =0;j<n;j++){
        if(ok(bor,x,j,n)) {
            bor[x][j] = 'Q';
            helper(ans,n,bor,x+1);
            bor[x][j] = '.';
            }
    }      
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> bor(n, vector<char>(n));
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                bor[i][j] = '.';
            }
        }
        helper(ans,n,bor,0);
        return ans;
    }
};