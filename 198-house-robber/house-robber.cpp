class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0]; 
        dp[1] = max(nums[0],nums[1]);

        for(int i =2;i<n;i++){
            dp[i] = max( nums[i]+dp[i-2] , dp[i-1]);
        }
    return dp[n-1];
    }
};
// class Solution {
// public:
//     int hlpr(vector<int> &nums,int ix){
//         if(ix>=nums.size()) return 0;
//         int take = nums[ix] + hlpr(nums,ix+2);
//         int skip = hlpr(nums,ix+1);
//         return max(skip,take);
//     }
//     int rob(vector<int>& nums) {
//     return hlpr(nums,0);
//     }
// };