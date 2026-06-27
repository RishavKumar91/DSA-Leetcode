class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,long long> mp;
        for(int & x: nums) mp[x]++;
        int  ans = 1 ;
        if(mp.count(1) ) ans = mp[1]%2==0 ? mp[1]-1 : mp[1];
        mp.erase(1);
        for(auto &[x,frq] : mp){
            long long curr = x;
            int ln = 0 ;
            while (mp.count(curr) && mp[curr] >= 2) {
                ln += 2;
                curr *= curr;
            }
            if (mp.count(curr) && mp[curr] == 1) ln++;
            else ln--;
            ans = max(ans,ln);
        }
        return ans;
    }
};