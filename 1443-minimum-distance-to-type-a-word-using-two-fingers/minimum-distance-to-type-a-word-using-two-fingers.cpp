class Solution {
public:
string words;
    int getdist(int F1,int F2){
        if(F1==26) return 0; 
        return abs(F2/6-F1/6) + abs(F2%6-F1%6);
    }
    int solv(int ix,int F1,int F2, vector<vector<vector<int>>> &dp){
        if(ix==words.size()) return 0;
        if(dp[ix][F1][F2] != -1) return dp[ix][F1][F2] ;
        int curr = words[ix]-'A';
        int MovF1 = getdist(F1 , curr) + solv(ix+1 , curr , F2,dp);
        int MovF2 = getdist(F2 , curr) + solv(ix+1 , F1 , curr,dp);
        return dp[ix][F1][F2] =  min(MovF1,MovF2);
    }
    int minimumDistance(string word) {
        words = word;
        vector<vector<vector<int>>> dp(word.size()+1,vector<vector<int>>(27,vector<int>(27, -1)));
        return solv(0,26,26,dp);
    }
};