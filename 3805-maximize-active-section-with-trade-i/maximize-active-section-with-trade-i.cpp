class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int now = 0 ; 
        for(char &ch : s){
            if(ch == '1') now++;
        }
        s = "1" + s + "1";
        vector<pair<char,int>> runningchar;
        for(char &ch : s){
            if(runningchar.empty() || runningchar.back().first != ch ) runningchar.push_back({ch,1});
            else runningchar.back().second++;
        }
        int ans  = now ;
        for(int i  = 1 ; i < runningchar.size()-1 ; i++){
            if(runningchar[i-1].first == '0' && runningchar[i].first == '1' && runningchar[i+1].first == '0' ){
                ans = max(ans,  now + runningchar[i-1].second + runningchar[i+1].second);
            }
        } 
        return ans;
    }
};