class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        pair<int,int> s = {0,1};
        int x = 0,y=0;
        set<pair<int,int>> sst;
        for( auto obs : obstacles){
            sst.insert({obs[0],obs[1]});
        }
        int ans = 0;
        for(int c : commands){
            if(c == -2){
                s = {-s.second,s.first};
            }
            else if(c == -1){
                s = {s.second,-s.first};
            }
            else {
                for(int i = 0 ;i<c ; i++){
                    int nx = x + s.first;
                    int ny = y + s.second;
                    if(sst.count({nx,ny})) break;
                    x = nx; y = ny ;
                    ans = max(ans , x*x + y*y);
                }
            }
        }
    return ans;
    }
};