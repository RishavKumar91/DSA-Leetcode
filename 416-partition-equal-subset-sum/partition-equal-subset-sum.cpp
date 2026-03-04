class Solution {
public:
bool chck(vector<int> &nums , int target,int ix,int now,vector<vector<int>> & dp){
    if(target==now) return 1;
    if(ix==nums.size()) return 0;
    if(dp[ix][now] != -1) return dp[ix][now];
    bool skip = chck(nums,target,ix+1,now,dp);
    bool take = 0;
    if(nums[ix]+now>target){
        take = chck(nums,target,ix+1,now,dp);
    }
    else take = chck(nums,target,ix+1,now+nums[ix],dp);
    return dp[ix][now] =  take || skip;
}
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum +=x;
        if(sum%2==1) return 0;
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum/2 +1, -1));
        return chck(nums,sum/2,0,0,dp);
    }
};