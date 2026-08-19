class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int mask1 = 1<<2 | 1<<3 | 1<<4 | 1<<5;
        int mask2 = 1<<6 | 1<<7 | 1<<4 | 1<<5;
        int mask3 = 1<<6 | 1<<7 | 1<<8 | 1<<9;
        unordered_map<int,int> mp ;
        for(auto &v : reservedSeats ){
            mp[v[0]] = ( mp[v[0]] | (1<<v[1]));
        }
        int ans = 2LL * (n-mp.size());
        for(auto &x : mp){
            bool ans1 = !(mask1 & x.second);
            bool ans2 = !(mask2 & x.second);
            bool ans3 = !(mask3 & x.second);
            if(ans1 && ans3) ans+=2;
            else if(ans2 || ans1 || ans3) ans+=1;
        }
    return ans;
    }
};