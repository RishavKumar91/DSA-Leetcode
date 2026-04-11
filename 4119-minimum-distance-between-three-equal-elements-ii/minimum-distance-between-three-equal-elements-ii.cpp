class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX ;
        vector<vector<int>> v(n+1);
        for(int i = 0;i<n;i++){
            v[nums[i]].push_back(i);
            if(v[nums[i]].size() >= 3) {
                vector<int> &anss = v[nums[i]];
                ans = min(ans,i-anss[anss.size()-3]);
            }
        }
    return ans == INT_MAX ? -1 : 2 * ans;
    }
};