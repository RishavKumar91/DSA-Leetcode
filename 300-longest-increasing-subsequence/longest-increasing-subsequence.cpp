class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tmp;
        int n = nums.size();
        tmp.push_back(nums[0]);
        for(int i = 1 ;i < n ; i++){
            int curr = nums[i];
            if(tmp.back() < curr) tmp.push_back(curr);
            else{
                auto it = lower_bound(tmp.begin(),tmp.end(),curr);
                *it = curr;
            }
        }
    return tmp.size();
    }
};