class Solution {
public:
vector<int> ans;
void hlpr(int now){
    if(now==0) return ;
    hlpr(now/10);
    ans.push_back(now%10);
}
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ;i<n;i++){
            if(nums[i]==0) ans.push_back(0);
            else hlpr(nums[i]);
        }
    return ans;
    }
};