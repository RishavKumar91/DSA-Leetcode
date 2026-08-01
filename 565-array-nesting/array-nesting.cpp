class Solution {
public:
int n;
vector<int> dp ; 
int hlpr(vector<int>& nums , int i,vector<bool> &visit){
    if(visit[nums[i]]) return 0;
    if(dp[i] != -1) return dp[i];
    visit[nums[i]] = 1;
    return dp[i] =  1 + hlpr(nums,nums[i],visit);
}
    int arrayNesting(vector<int>& nums) {
        n = nums.size();
        int ans = 0 ;
        dp.resize(n+1,-1);
        vector<bool> visit(n+1,0);
        for(int i = 0 ; i < n ; i++){
            if(visit[nums[i]]) continue;
            ans = max(ans,hlpr(nums,nums[i],visit));
        }
        return ans ; 
    }
};