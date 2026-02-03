class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n-1 && nums[i+1]>nums[i]){
            i++;
        }
        if(i==0 || i==n-1) return 0;
        while(i<n-1 && nums[i+1]<nums[i]){
            i++;
        }
        if(i==0 || i==n-1) return 0;
        while(i<n-1 && nums[i+1]>nums[i]){
            i++;
        }

        if(i==n-1) return 1;
        else return 0;
    }
};