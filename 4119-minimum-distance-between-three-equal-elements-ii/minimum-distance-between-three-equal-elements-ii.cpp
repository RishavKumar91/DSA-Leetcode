class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX ;
        vector<queue<int>> v(n+1);
        for(int i = 0;i<n;i++){
            v[nums[i]].push(i);
            if(v[nums[i]].size() == 3) {
                ans = min(ans,i-v[nums[i]].front());
                v[nums[i]].pop();
            }
        }
    return ans == INT_MAX ? -1 : 2 * ans;
    }
};