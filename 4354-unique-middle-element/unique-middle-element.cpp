class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int mid = nums[n/2];
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == mid) count++;
            if(count >= 2) return 0;
        }
    return count;
    }
};