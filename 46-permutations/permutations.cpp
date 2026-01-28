class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int> &nums,int ix){
        if(ix==nums.size()){
            ans.push_back(nums);
        }
        for(int i =ix;i<nums.size();i++){
            swap(nums[i],nums[ix]);
            helper(ans,nums,ix+1);
            swap(nums[i],nums[ix]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>  ans;
        vector<int> v;
        helper(ans,nums,0);
        return ans;
    }
};