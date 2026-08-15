class Solution {
public:
int m , n ;
    vector<pair<int,int>> dxn = {{0,1},{0,-1},{1,0},{-1,0}};
    bool hlpr(vector<vector<char>>& board, string word , int a ,int i,int j,vector<vector<bool>> &visit){
        if(board[i][j] != word[a]) return 0;
        if(a == word.size()-1){
            return 1;
        }
        visit[i][j] = 1;
        for(auto &d : dxn){
            int ni = i + d.first, nj = j + d.second;
            if(ni >= m || nj >=n || ni < 0 || nj < 0 || visit[ni][nj]) continue;
            if(hlpr(board,word,a+1,ni,nj,visit)) return 1; 
        }
        visit[i][j] = 0;
    return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size() , n = board[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0]) {
                    vector<vector<bool>> visit(m+1,vector<bool> (n+1,0));
                    visit[i][j] = 1;
                    if(hlpr(board,word,0,i,j,visit)){
                        return 1;
                    }
                    visit[i][j] = 0;
                }
            }
        }
        return 0;
    }
};