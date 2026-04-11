class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int> > mp;
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size() >= 3){
                vector<int> &v = mp[nums[i]];
                ans = min(ans, i - v[v.size()-3] );
            }
        }
    return ans ==INT_MAX ? -1 : 2  * ans;
    }
};