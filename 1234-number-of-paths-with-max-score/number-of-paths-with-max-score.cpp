class Solution {
public:
int n  , M = 1e9+7;
vector<vector<pair<int,int>>> dp;
    pair<int,int> hlpr(int i , int j , vector<string>& board){
        if(i==0 && j==0) return {0,1};
        if(i<0 || j < 0 || board[i][j] == 'X') return {0,0};
        if(dp[i][j] != make_pair(-1,-1)) return dp[i][j];
        auto [upscor , uppaths] = hlpr(i-1,j,board);
        auto [lftscor, lftpaths] = hlpr(i,j-1,board);
        auto [uplftscor, uplftpaths] = hlpr(i-1,j-1,board);
        if(uppaths > 0 ) upscor += board[i][j] != 'S' ? board[i][j]-'0' : 0 ; 
        if(lftpaths > 0 ) lftscor += board[i][j] != 'S' ? board[i][j]-'0' : 0 ; 
        if(uplftpaths > 0 ) uplftscor += board[i][j] != 'S' ? board[i][j]-'0' : 0 ; 
        int mx = max({upscor,lftscor,uplftscor});
        int mxpaths = 0;
        if(mx==upscor) mxpaths = (mxpaths + uppaths)%M;
        if(mx==lftscor) mxpaths = (mxpaths + lftpaths)%M;
        if(mx==uplftscor) mxpaths = (mxpaths + uplftpaths)%M;
    return dp[i][j] ={mx,mxpaths};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        dp.assign(n,vector<pair<int,int>> (n,{-1,-1}));
        pair<int,int> p = hlpr(n-1,n-1,board);
        return {p.first , p.second};
    }
};