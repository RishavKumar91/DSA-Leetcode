class Solution {
public:
vector<vector<int>> ans;
void hlpr(vector<int> &nums,vector<int> tmp , int i){
    if(i==nums.size()) {
        ans.push_back(tmp);
        return ;
    }
    hlpr(nums,tmp,i+1);
    tmp.push_back(nums[i]);
    hlpr(nums,tmp,i+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        hlpr(nums,{},0);
        return ans;
    }
};