class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> ans(2,0);
        int n = moves.size();
        for(int i = 0;i<n;i++){
            if(moves[i]=='U') ans[0]++;
            else if(moves[i]=='D') ans[0]--;
            else if(moves[i]=='L') ans[1]++;
            else ans[1]--;
        }
        if(ans[0]!=0 || ans[1] != 0) return 0;
        return 1;
    }
};