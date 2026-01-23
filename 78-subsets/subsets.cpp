class Solution {
public:
void helper(vector<vector<int>> &ans,vector<int> &nums,vector<int> v,int idx){
    if(nums.size()==idx) {
        ans.push_back(v);
        return;
    }
    helper(ans,nums,v,idx+1);
    v.push_back(nums[idx]);
    helper(ans,nums,v,idx+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> k;
        vector<int> v;
        helper(k,nums,v,0);
        return k;
    }
};